#!/bin/bash

# constants
SUPPORTED_PLATFORMS=("GitHub" "Other" "Medium")
FOLDER_NOTES="$HOME/Documents/Notes"
FOLDER_JOURNAL="$HOME/Documents/Journal"
FOLDER_DAILY="$HOME/Documents/Journal/Daily"

# functions

# create MarkDown file

create_md_file() {
  local filename="$1"
  local folder="$2"

  # change to the appropriate folder
  cd "$folder"

  # check for daily file
  if [[ $folder == $FOLDER_DAILY ]]; then

    cat <<EOF >"$filename.md"
---
created: $(date +%c)
tags: +Daily 
---
# $(date +%D\ %a)
Welcome to daily notes!
## Must Done Tasks
- [] task1
- [] task2
- [] task
## Ideas
- [] idea1
- [] idea2
- [] idea
## Cal | Email | Texts
- person1
- person2
- person3

EOF

    nvim "$(date +%4Y-%m-%d).md"
  else

    # prompt user for title and tags
    read -p "Enter the title: " title
    read -p "Enter tags (comma-separated): " tags

    # create the file
    cat <<EOF >"$filename.md"
---
title: $title
tags: $tags
---

# $title

EOF

    nvim "$filename.md"
  fi

  # open file in NeoVim

  # Wait for user to exit NeoVim
  read -p "Press Enter to continue..."

  echo "MarkDown file '$filename.md' created and opened in NeoVim at '$folder'."

  # keeping log
  echo "[$(date +%D\ %H:%M)] '$filename.md'at '$folder'." >>"$HOME/Documents/log/annote.log"
}

# publish MarkDown file
# to selected platforms
publish_md_file() {
  local filename="$1"
  local folder="$2"

  # check if the file exists
  if [[ -f "$folder/$filename.md" ]]; then
    # prompt use to select publication platforms
    echo "Where do you want to publish file?"
    for i in "${!SUPPORTED_PLATFORMS[@]}"; do
      echo "$((i + 1)). ${SUPPORTED_PLATFORMS[$i]}"
    done

    echo "$((${#SUPPORTED_PLATFORMS[@]} + 1)). cancel"
    read -p "Enter your choice: " platform_choice

    # handle the user's choice
    case "$platform_choice" in
    [1-${#SUPPORTED_PLATFORMS[@]}])
      platform=${SUPPORTED_PLATFORMS[$((platform_choice - 1))]}
      echo "Publishing to $platform..."

      case "$platform" in
      "Medium")
        publish_to_medium "$filename" "$folder"
        ;;
      "GitHub")
        publish_to_github "$filename" "$folder"
        ;;
      "Dev.to")
        publish_to_devto "$filename" "$folder"
        ;;
      *)
        echo "Publishing to $platform is not implemented yet."
        ;;
      esac

      ;;
    $((${#SUPPORTED_PLATFORMS[@]} + 1)))
      echo "Cancelling publication..."
      return
      ;;
    *)
      echo "Invalid choice please try again."
      publish_md_file "$filename" "$folder"
      ;;
    esac

    echo "MarkDown file published successfully!"
  else
    echo "Error: File '$folder/$filename.md' does not exist."
  fi
}

# publish to Medium
publish_to_medium() {
  local filename="$1"
  local folder="$2"
  local title=$(grep "^title:" "$folder/$filename.md" | cut -d ':' -f2 | tr -d '[:space]')
  local tags=$(grep "^tags:" "$folder/$filename.md" | cut -d ':' -f2 | tr -d '[:space]')

  # prompt user for their Medium api and credentials
  read -p "Enter your Medium username: " medium_username
  read -p "Enter your Medium API key: " medium_api_key

  # publish the file to Medium
  response=$(
    curl -X POST \
      -H "Content-Type: application/json" \
      -H "Authorization: Bearer $medium_api_key" \
      -d "{\"title\":\"$title\",\"tags\":\"$tags\",\"content\":\"$(cat "$folder/$filename.md")\",\"publishStatus\":\"public\"}" \
      https://api.medium.com/v1/users/$medium_username/posts
  )
  if [[ $response =~ "\"url\":" ]]; then
    echo "MarkDown published to Medium successfully!"
  else
    echo "Failed to publish MarkDown file to Medium. Error: $response"
  fi
}

# open md file function
open_md_file() {
  local filename="$1"
  local folder="$2"

  # check if file exists
  if [[ -f "$folder/$filename.md" ]]; then
    nvim "$folder/$filename.md"
  else
    echo "File does not exists at '$folder/$filename.md'"
  fi
}

# remove md file
remove_md_file() {
  local filename="$1"
  local folder="$2"

  if [[ -f "$folder/$filename.md" ]]; then
    rm "$folder/$filename.md"

    # keeping log
    echo "[$(date +%D\ %H:%M)] 'Removed $filename.md'at '$folder'." >>"$HOME/Documents/log/annote.log"
  else
    echo "File does not exist ar '$folder/$filename.md'"
  fi

}

# help function
help() {
  echo "Usage: $0 [note|journal|daily] [--create|--publish|--open|--remove] [<filename>]"
  echo "For Daily: $0 daily [--create|--open|--remove]"
}

# main function
# handles cli arguments and calls function needed

if [[ "$#" -lt 2 || "$#" -gt 3 ]]; then
  help
  exit 1
fi

case "$1" in
"note")
  folder="$FOLDER_NOTES"
  ;;
"journal")
  folder="$FOLDER_JOURNAL"
  ;;
"daily")
  folder="$FOLDER_DAILY"
  ;;
*)
  echo "Invalid folder type. Please use 'note', 'journal', or 'daily'."
  exit 1
  ;;
esac

case "$2" in
"--create")
  if [[ "$#" -lt 2 && "$#" -gt 3 ]]; then
    help
    exit 1
  fi
  if [[ "$1" == "daily" ]]; then
    create_md_file "$(date +%4Y-%m-%d)" "$folder"
  else
    create_md_file "$3" "$folder"
  fi
  ;;
"--publish")
  if [[ "$#" -ne 3 ]]; then
    help
    exit 1
  fi
  publish_md_file "$3" "$folder"
  ;;
"--open")
  if [[ "$#" -lt 2 && "$#" -gt 3 ]]; then
    help
    exit 1
  fi
  if [[ "$1" == "daily" ]]; then
    open_md_file "$(date +%4Y-%m-%d)" "$folder"
  else
    open_md_file "$3" "$folder"
  fi
  ;;
"--remove")
  remove_md_file "$3" "$folder"
  ;;
*)
  echo "Invalid command. Please use '--create', '--publish', '--open' or '--remove'."
  exit 1
  ;;
esac
