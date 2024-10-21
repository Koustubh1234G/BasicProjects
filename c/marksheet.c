#include<stdio.h>
#include<conio.h>
//#include<math.h>

int main(){
    printf("\t\t\tRBSE 12 Class Result\n");
    printf("\nBoard OF Secondary Educarion Rajasthan\n");
    printf("Result: Sr. Sec. Madhyamik Shiksha Examination, 2022\n");
    
    //input roll no.
    int rn;
    printf("\nRoll no. ");
    scanf("%d",rn);
    printf("\nSchool: Shreeji School, Nathdwara\n");

    //student details
    printf("\nName: Koustubh Dave");
    printf("\nFathers Name: Dinesh Dave");
    printf("\nMothers Name: Indra Dave");

    //marks distribution
    int hindi,eng,math,phy,chem;
    printf("\n\nSubjects\t\t\tMarks Obtained");
    printf("\nHindi\t\t\t");
    scanf("%d",hindi);
    printf("\nEnglish\t\t\t");
    scanf("%d",eng);
    printf("\nMathematics\t\t\t");
    scanf("%d",math);
    printf("\nPhysics\t\t\t");
    scanf("%d",phy);
    printf("\nChemistry\t\t\t");
    scanf("%d",chem);
    
    //total and percentage
    int t=1;
    float per;
    t=hindi+eng+math+phy+chem;
    per=(t/500.00)*100;
    printf("\n\nTotal\t\t\t%d",t);
    printf("\nPercentage\t\t\t%f",per);

    //declaring result
    if (per<=33.00)
    {
        printf("\n\nFail!!");
    }
    else{
        printf("\n\nPass!!");
    }
    
    getch();
}

/*

Mermaid Flowchart
graph TD
    A([Start])-->B[declare rn,name,fname,mname,eng,hindi,math,phy,chem,t,per]
    B-->C[/"print #quot;School info#quot;"/]
    C-->D[/read rn/]-->E[/print roll no and school name/]
    E-->F[/read name,fname,mname/]-->G[/print student details/]
    G-->H[/read hindi,eng,math,phy.chem/]-->I[/print marks obtained for each subject/]
    I-->J["t=hindi+eng+math+phy+chem, per=(t/500.00)*100"]
    J-->K[/print total t and percentafe per/]
    K-->L{If per<=33.33}
    L-->|True|M[/print Fail!!/]
    L-->|False|N[/print Pass!!/]
    M-->O([Stop])
    N-->O
  

*/