#!/bin/bash

POMODORO_DURATION=1500   # 25 minutes
SHORT_BREAK_DURATION=300 # 5 minutes
LONG_BREAK_DURATION=900  # 15 minutes
POMODOROS_BEFORE_LONG_BREAK=4
LOG_FILE="$HOME/Documents/log/pomo.log"

pomodoros_completed=0

display_timer() {
  local time_left=$1
  local minutes=$((time_left / 60))
  local seconds=$((time_left % 60))
  zenity --notification --window-icon=info --text="Time left: $minutes:$seconds"
}

log_event() {
  local event=$1
  local timestamp=$(date '+%Y-%m-%d %H:%M:%S')
  echo "[$timestamp] $event" >>"$LOG_FILE"
}

run_pomodoro() {
  while true; do
    local start_time=$(date +%s)
    log_event "Pomodoro started"
    while true; do
      local time_left=$((POMODORO_DURATION - ($(date +%s) - start_time)))
      if [ $time_left -le 0 ]; then
        log_event "Pomodoro completed"
        zenity --notification --window-icon=info --text="Pomodoro complete! Time for a break."
        ((pomodoros_completed++))
        break
      fi
      if [ $((time_left % 30)) -eq 0 ]; then
        display_timer "$time_left"
      fi
      read -t 1 -n 1 key
      if [ "$key" == "q" ]; then
        return
      elif [ "$key" == "p" ]; then
        time_left=$(pause_timer "$start_time")
        start_time=$(($(date +%s) - (POMODORO_DURATION - time_left)))
      fi
    done

    # Short break
    start_time=$(date +%s)
    log_event "Short break started"
    while true; do
      time_left=$((SHORT_BREAK_DURATION - ($(date +%s) - start_time)))
      if [ $time_left -le 0 ]; then
        log_event "Short break completed"
        zenity --notification --window-icon=info --text="Break over, time to start another Pomodoro."
        break
      fi
      if [ $((time_left % 30)) -eq 0 ]; then
        display_timer "$time_left"
      fi
      read -t 1 -n 1 key
      if [ "$key" == "q" ]; then
        return
      fi
    done

    if [ $((pomodoros_completed % POMODOROS_BEFORE_LONG_BREAK)) -eq 0 ] && [ $pomodoros_completed -gt 0 ]; then
      start_time=$(date +%s)
      log_event "Long break started"
      while true; do
        time_left=$((LONG_BREAK_DURATION - ($(date +%s) - start_time)))
        if [ $time_left -le 0 ]; then
          log_event "Long break completed"
          zenity --notification --window-icon=info --text="Long break over, time to start another Pomodoro."
          break
        fi
        if [ $((time_left % 30)) -eq 0 ]; then
          display_timer "$time_left"
        fi
        read -t 1 -n 1 key
        if [ "$key" == "q" ]; then
          return
        fi
      done
    fi
  done
}

pause_timer() {
  local original_start_time=$1
  local pause_start_time=$(date +%s)
  while true; do
    read -t 120 -n 1 key
    if [ "$key" == "p" ]; then
      local pause_duration=$(($(date +%s) - pause_start_time))
      local remaining_time=$((POMODORO_DURATION - ($(date +%s) - original_start_time) + pause_duration))
      display_timer "$remaining_time"
      return $remaining_time
    fi
  done
}

run_pomodoro
