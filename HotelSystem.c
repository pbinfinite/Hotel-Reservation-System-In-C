#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
int loginform();
void display();
void append(int noofc);
void searchdata();
void searchanddisp();
void modify();
void removedata();
void roomdata();
void setcolor();
void exit();

struct login_info
{
    char username[30];
    char password[10];
};
struct custm
{
    int slno;
    char cname[30];
    int roomno;
    long long int phno;
    char email[50];
    int days;
    int totalamt;
    int paidamt;
    int balamt;
    char roomtype[20];
};
int singlet,doublet,deluxet;
int singleb,doubleb,deluxeb;  //available =total- booked
int total,totalb,totala;
void firstme()
{
    FILE *fp;
    fp=fopen("roomhotel.txt","r");
    if(fp==NULL)
        printf("Incorrect file.\n");
    else{
    fscanf(fp,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",&singlet,&doublet,&deluxet,&singleb,&doubleb,&deluxeb,&total,&totalb,&totala);
    fclose(fp);}
}

void endwithme()
{
        FILE *fp;
        fp=fopen("roomhotel.txt","w");
        if(fp==NULL)
            printf("Incorrect file.\n");
        else{
        totalb=singleb+doubleb+deluxeb;
        totala=total-totalb;
        fprintf(fp,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",singlet,doublet,deluxet,singleb,doubleb,deluxeb,total,totalb,totala);
        fclose(fp);}
}

int main()
{

    int chc,flag=1;
    int c,noofc;
    firstme();
    int i=0,j;
	char customername;
	char choice;

	system("cls");
    setcolor(11) ;

	printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                         |\n");
	printf("|                                                                         |\n");
	printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOO   OOOOOO   |\n");
	printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("|  O  OOO   OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOO   OOOOOO   |\n");
	printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("|                                                                         |\n");
	printf(" -------------------------------------------------------------------------\n");
 	printf("\t\t*********************************************************\n");
	printf("\t\t*                                                       *\n");
	printf("\t\t*       ---------------------------------               *\n");
	printf("\t\t*             WELCOME TO HOTEL PINNACLE                 *\n");
	printf("\t\t*       ---------------------------------               *\n");
	printf("\t\t*                                                       *\n");
	printf("\t\t*                                                       *\n");
	printf("\t\t*                                                       *\n");
	printf("\t\t*        CONTACT US:9999999999,9000000000               *\n");
	printf("\t\t*********************************************************\n\n\n");
		for(i=0;i<80;i++)
		printf("-");
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");

	getch();
    system("cls");

    system("cls");
    printf("Welcome to Hotel PINNACLE PARADISE\n");//Print used by whom
    int lin=loginform();
    if(lin==0){
        printf("\nTry again later\n");
        return 0;
    }
    while(flag==1){
    system("cls");
    setcolor(15);
    printf("\nSelect option\n\n");
    printf("1.Display all customer data\n2.Append records\n3.Search\n4.Modify a record\n5.Search and display record\n6.Delete a customer record\n7.Room availability information\n8.Exit\n");
    scanf("%d",&chc);
    switch(chc){
        case 1:display();flag=0;break;
        case 2:{
            system("cls");
            printf("Number of customers: ");scanf("%d",&noofc);
            for(j=0;j<noofc;j++)
            {append(noofc);}
            flag=0;break;}
        case 3:searchdata();flag=0;break;
        case 4:modify();endwithme();firstme();flag=0;break;
        case 5:searchanddisp();flag=0;break;
        case 6:removedata();endwithme();firstme();flag=0;break;
        case 7:roomdata();flag=0;break;
        case 8:endwithme();printf("Thanks for visiting. Have a nice day !\n");exit(0);
        default:printf("Incorrect number\n");flag=1;break;
    }
    printf("Would you like to continue to use our database ..?\nEnter\n1.Yes or \n2.No\n");
    scanf("%d",&c);
    if(c==1){
        flag=1;
    }
    else if(c==2){
        flag=0;
        printf("Thanks for visiting.Have a nice day !\n");
        endwithme();
                }}
    return 0;
}

int loginform()
{
    char uname[30]; char pword[10],cc=' ';int ch;
    int uk=0,pk=0,i,ii=0;
    int status=0,attempts=0;
    struct login_info lg;
    printf("\n  **************************  LOGIN FORM  **************************  ");
    FILE *fp;
    fp=fopen("loginid.txt","r");
    if(fp==NULL)
        printf("Incorrect file.\n");
    else{
      while(attempts!=3){
        printf("\nUsername: ");
        scanf("%s",uname);
        printf("Password: ");
        ii=0;
        while(ii<10)
	{
	    pword[ii]=getch();
	    cc=pword[ii];
	    if(cc==13) break;
	    else printf("*");
	    ii++;
	}
	pword[ii]='\0';
        fseek(fp,0,SEEK_SET);
        attempts++;
        while(!feof(fp))
        {
            if(fscanf(fp,"%s\t\t%s",lg.username,lg.password)!=2)
                break;
            if(strcmp(lg.username,uname)==0)
                uk=1;
            if(strcmp(lg.password,pword)==0)
                pk=1;
        }
        fseek(fp,0,SEEK_SET);
        if(uk==1 && pk==1){
            printf("\nLOGIN SUCCESSFUL\n"); status=1; return 1;}
        if(uk!=1)
            printf("\nIncorrect username\n");
        if(pk!=1)
            printf("\nIncorrect password\n");
        if(attempts!=3)
            printf("\nPlease enter correct data\n");
        }
        system("cls");
        fclose(fp);
        return 0;}




}

void display()
{
    setcolor(10);
    system("cls");
    FILE *fp;
    int i;
    struct custm ct;
    fp=fopen("hoteldb2.txt","r");
    if(fp==NULL){
        printf("Not opening. Please provide the correct file.\n");
    }
    else{
        //printf("Opened\n");
        printf("C-no.\t\tName\t\t\tRoomno.\t\tRoomType\tPh.no\t\t\tDays\t\tTotal.amt.\tPaid.amt.\tBalance\t\tEmail-id\n");
        while(!feof(fp)){
        if(fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",&ct.slno,ct.cname,&ct.roomno,ct.roomtype,&ct.phno,&ct.days,&ct.totalamt,&ct.paidamt,&ct.balamt,ct.email)!=10)
            break;
        printf("%d\t\t%s\t\t\t%d\t\t%s\t\t%lld\t\t",ct.slno,ct.cname,ct.roomno,ct.roomtype,ct.phno);
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ct.days,ct.totalamt,ct.paidamt,ct.balamt,ct.email);}
        fclose(fp);}
    //printf("File closed \n");
}
void append(int noofc)
{
    //system("cls");
    setcolor(10);
    FILE *fp;
    int i,j,oldct;
    int lcno;
    int t1=0,t2=0;
    struct custm ct[30];
    struct custm ctemp;
    fp=fopen("hoteldb2.txt","r");
    if(fp==NULL){
        printf("Not opening. Please provide the correct file.\n");
    }
    else{
        //printf("Opened\n");
        i=0;
        while(!feof(fp)){
            if(fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",&ct[i].slno,ct[i].cname,&ct[i].roomno,ct[i].roomtype,&ct[i].phno,&ct[i].days,&ct[i].totalamt,&ct[i].paidamt,&ct[i].balamt,ct[i].email)!=10)
                break;
            lcno=ct[i].slno;
            i++;}
        oldct=i-1;
    }
    //printf("%d\n",oldct);
    fclose(fp);
    //printf("Closed\n");
    int sg[50],db[50],dlx[50];
    int p,h,z=0,f=0;

    fp=fopen("hoteldb2.txt","a");
    if(fp==NULL){
        printf("Not opening. Please provide the correct file.\n");
    }
    else{
        //printf("Opened\n");
        if(total-totalb<noofc)
        {
            printf("No available rooms..Sorry !!\n");
            return;
        }
        ctemp.slno=lcno+1;
        printf("\nCustomer no.: %d\n",ctemp.slno);
        for(j=0;j<oldct;j++){
            if((ctemp.slno)==(ct[j].slno)){
                printf("Customer no already exists\n");
                printf("Enter again.\nCustomer no:");
                scanf("%d",&ctemp.slno);}
        }
        printf("Name: ");scanf("%s",ctemp.cname);
        printf("Room type(single,double or deluxe):"); scanf("%s",ctemp.roomtype);
        if(strcmp(ctemp.roomtype,"single")==0){
            if(singleb==50){
                printf("All single rooms booked.\n");
                return;}
            else{
                singleb=singleb+1;
                printf("Single rooms available for booking :\n");
                for(p=101;p<151;p++){
                    for(h=0;h!=oldct+1;h++){
                      if(ct[h].roomno<151){
                        if(p==ct[h].roomno){
                            f=1;break;}}}
                if(f==0){
                    sg[z]=p;z++;}
                f=0;
                }
                sg[z]='\0';
                for(h=0;sg[h+1]!='\0';h++)
                    printf("%d,",sg[h]);
                printf("%d\n",sg[h]);
                while(t1==0 || t2==0){
                printf("\nEnter room no.(101-150): "); scanf("%d",&ctemp.roomno);
                if(ctemp.roomno<101 || ctemp.roomno>150){
                    printf("Invalid.\n"); t1=0;
                }
                else{
                    t1=1;
                    for(j=0;j<oldct;j++){
                    if((ctemp.roomno)==(ct[j].roomno)){
                        printf("Room already booked.\n");t2=0; break;}
                    else
                        t2=1;
                    }
                }}}}
        if(strcmp(ctemp.roomtype,"double")==0){
            if(doubleb==50){
                printf("All double rooms booked.\n");
                return;}
            else{
                doubleb=doubleb+1;
                printf("Double rooms available for booking :\n");
                for(p=201;p<251;p++){
                    for(h=0;h!=oldct+1;h++){
                      if(ct[h].roomno>200 && ct[h].roomno<251){
                        if(p==ct[h].roomno){
                            f=1;break;}}}
                if(f==0){
                    db[z]=p;z++;}
                f=0;
                }
                db[z]='\0';
                for(h=0;db[h+1]!='\0';h++)
                    printf("%d,",db[h]);
                printf("%d\n",db[h]);
                while(t1==0 || t2==0){
                printf("\nEnter room no.(201-250): "); scanf("%d",&ctemp.roomno);
                if(ctemp.roomno<201 || ctemp.roomno>250){
                    printf("Invalid.\n"); t1=0;
                }
                else{
                    t1=1;
                    for(j=0;j<oldct;j++){
                    if((ctemp.roomno)==(ct[j].roomno)){
                        printf("Room already booked.\n");t2=0; break;}
                    else
                        t2=1;
                    }
                }}
                }}
        if(strcmp(ctemp.roomtype,"deluxe")==0){
            if(deluxeb==50){
                printf("All deluxe rooms booked.\n");
                return;}
            else{
            deluxeb=deluxeb+1;
            printf("Deluxe rooms available for booking :\n");
                for(p=301;p<351;p++){
                    for(h=0;h!=oldct+1;h++){
                      if(ct[h].roomno>300 && ct[h].roomno<351){
                        if(p==ct[h].roomno){
                            f=1;break;}}}
                if(f==0){
                    dlx[z]=p;z++;}
                f=0;
                }
                dlx[z]='\0';
                for(h=0;dlx[h+1]!='\0';h++)
                    printf("%d,",dlx[h]);
                printf("%d\n",dlx[h]);
            while(t1==0 || t2==0){
            printf("\nEnter room no.(301-350): "); scanf("%d",&ctemp.roomno);
                if(ctemp.roomno<301 || ctemp.roomno>350){
                    printf("Invalid.\n"); t1=0;
                }
                else{
                    t1=1;
                    for(j=0;j<oldct;j++){
                    if((ctemp.roomno)==(ct[j].roomno)){
                        printf("Room already booked.\n");t2=0; break;}
                    else
                        t2=1;
                    }
                }}
            }}

        printf("Phone no: ");scanf("%lld",&ctemp.phno);
        printf("Email-id: ");scanf("%s",ctemp.email);
        printf("Days: ");scanf("%d",&ctemp.days);
        printf("Total amt: ");scanf("%d",&ctemp.totalamt);
        int g=0;
        while(g==0){
        printf("Paid amt: ");scanf("%d",&ctemp.paidamt);
        if(ctemp.paidamt>ctemp.totalamt){
                printf("Paid amt exceeds total amt.Please enter correct data.\n");g=0;
        }
        else{
            ctemp.balamt=ctemp.totalamt-ctemp.paidamt;g=1;}}
        fprintf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);

    //fputs("\n",fp);
    fclose(fp);}
    //printf("File closed \n");
}

void searchdata()
{
    setcolor(10);
    system("cls");
    FILE *fp; //Take 2nd pointer and do it
    int i,k=1;
    int srch=0;
    long long int d;
    char *p;
    char what[30];
    struct custm ctemp;
    fp=fopen("hoteldb2.txt","r");
    if(fp==NULL){
        printf("Not opening. Please provide the correct file.\n");
    }
    else{
        //printf("Opened\n");
        printf("In which field would you like to search ?");
        printf("Enter respective no for the field:\n1.C-no.\n2.Name\n3.Roomno.\n4.Roomtype (single/double/deluxe)\n5.Phone.no\n6.Email-id\n7.Days\n8.Totalamt\n9.Paid.amt\n10.Balamt\n");
        scanf("%d",&srch);
        printf("Enter the data to find :");
        scanf("%s",what);
        switch(srch){
        case 1:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if((atoi(what)==ctemp.slno))
                    {printf("Found\n");k=0;break;}
            }
                break;
        }
        case 2:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if(strcmp(what,ctemp.cname)==0)
                    {printf("Found\n");k=0;break;}
               }
            break;
        }
        case 3:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if((atoi(what)==ctemp.roomno))
                    {printf("Found\n");k=0;break;}
                }
            break;
        }
        case 4:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if(strcmp(what,ctemp.roomtype)==0)
                    {printf("Found\n");k=0;break;}
            }
        break;
        }
        case 5:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                d=strtoll(what,&p,10);
                if(d==(ctemp.phno))
                    {printf("Found\n");k=0;break;}
            }
        break;
        }
        case 6:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if(strcmp(what,ctemp.email)==0)
                    {printf("Found\n");k=0;break;}
            }
            break;
        }
        case 7:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if((atoi(what)==ctemp.days))
                    {printf("Found\n");k=0; break;}
            }
        break;
        }
        case 8:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                d=atoi(what);
                if((d==ctemp.totalamt))
                    {printf("Found\n");k=0; break;}
            }
            break;
        }
        case 9:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                d=atoi(what);
                if((d==ctemp.paidamt))
                    {printf("Found\n");k=0;break;}
            }
        break;
        }
        case 10:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                d=atoi(what);
                if((d==ctemp.balamt))
                    {printf("Found\n");k=0;break;}
            }
        break;
        }
        default:printf("Incorrect option\n");break;
        }
    if(k==1)
        printf("Not found\n");
    printf("\n");
    fclose(fp);}
    //printf("File closed \n");}
}
void searchanddisp()
{
    setcolor(10);
    system("cls");
    FILE *fp; //Take 2nd pointer and do it
    int i,k=1;
    long long int d;
    char *p;
    int srch=0,q;
    char what[30];
    struct custm ctemp;
    fp=fopen("hoteldb2.txt","r");
    if(fp==NULL){
        printf("Not opening. Please provide the correct file.\n");
    }
    else{
        //printf("Opened\n");
        printf("In which field would you like to search ?");
        printf("Enter respective no for the field:\n1.C-no.\n2.Name\n3.Roomno.\n4.Roomtype (single/double/deluxe)\n5.Phone.no\n6.Email-id\n7.Days\n8.Totalamt\n9.Paid.amt\n10.Balamt\n");
        scanf("%d",&srch);
        printf("Enter the data to find: ");
        scanf("%s",what);
        printf("C-no.\t\tName\t\tRoomno.\t\tRoomType\tPh.no\t\t\tDays\t\tTotal.amt.\tPaid.amt.\tBalance\t\tEmail-id\n");
        switch(srch){
        case 1:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if((atoi(what)==ctemp.slno))
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;break;}
            }
                break;
        }
        case 2:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if(strcmp(what,ctemp.cname)==0)
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;}
               }
            break;
        }
        case 3:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if((atoi(what)==ctemp.roomno))
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;break;}
                }
            break;
        }
        case 4:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if(strcmp(what,ctemp.roomtype)==0)
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;}
            }
        break;
        }
        case 5:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                d=strtoll(what,&p,10);
                if(d==(ctemp.phno))
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;break;}
            }
        break;
        }
        case 6:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if(strcmp(what,ctemp.email)==0)
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;break;}
            }
            break;
        }
        case 7:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                if((atoi(what)==ctemp.days))
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;}
            }
        break;
        }
        case 8:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                d=atoi(what);
                if((d==ctemp.totalamt))
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;}
            }
            break;
        }
        case 9:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                d=atoi(what);
                if((d==ctemp.paidamt))
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;}
            }
        break;
        }
        case 10:{
            while(!feof(fp)){
                fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email);
                d=atoi(what);
                if((d==ctemp.balamt))
                    {printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                    k=0;}
            }
        break;
        }
        default:printf("Incorrect option\n");break;
        }
        if(k==1)
            printf("Not found\n");
    fclose(fp);
    printf("\n");
    //printf("File closed \n");
    }
}
void modify()
{
    setcolor(10);
    system("cls");
    FILE *fp;
    FILE *fp1;
    int t1=0,t2=0;
    int i,flag=0,oldct,j;
    char what[30];
    struct custm ct[30];
    struct custm ctemp;
    int sby,upd;
    int w,z=0,f=0,h;
    int sg[50],db[50],dlx[50];
    char *p;
    fp=fopen("hoteldb2.txt","r");
    fp1=fopen("hoteltemp.txt","w");
    if(fp==NULL || fp1==NULL){
        printf("Not opening. Please provide the correct file.\n");
    }
    else{
        //printf("Opened\n");
        i=0;
        while(!feof(fp)){
            fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld%d\t\t%d\t\t%d\t\t%d\t\t%s",&ct[i].slno,ct[i].cname,&ct[i].roomno,ct[i].roomtype,&ct[i].phno,&ct[i].days,&ct[i].totalamt,&ct[i].paidamt,&ct[i].balamt,ct[i].email);
            i++;
        }
        oldct=i-1;
        //printf("%d\n",oldct);
        fseek(fp,0,SEEK_SET);
        printf("Enter the Customer-no of the record to be updated: ");
        scanf("%d",&sby);
        printf("Which field would you like to update:\n");
        printf("Enter respective no for the field:\n1.Name\n2.Roomtype(single/double/deluxe) & Room no.\n3.Phone.no\n4.Email-id\n5.Days\n6.Totalamt\n7.Paid.amt\n8.Balamt\n");
        scanf("%d",&upd);
        if(upd!=2){
        printf("Enter the new data:");
        scanf("%s",what);}
        if(upd==2){
            printf("Enter the new Roomtype:");
            scanf("%s",what);
        }
      while(!feof(fp))
        {
        if(fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email)!=10)
            break;
        if(ctemp.slno==sby){
                flag=1;
            //printf("Customer exists\n");
            switch(upd){
            case 1:{
                strcpy(ctemp.cname,what);
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                break;          //strcpy(dest,source)
                }
            case 2:{
                //changing room data based on old data
                if(strcmp(ctemp.roomtype,"single")==0){
                    singleb=singleb-1;}
                if(strcmp(ctemp.roomtype,"double")==0){
                    doubleb=doubleb-1;}
                if(strcmp(ctemp.roomtype,"deluxe")==0){
                    deluxeb=deluxeb-1;}

                strcpy(ctemp.roomtype,what);

                if(strcmp(ctemp.roomtype,"single")==0){
                    if(singleb==50){
                        printf("All single rooms booked.\n");
                        break;}
                    else{
                        singleb=singleb+1;
                        printf("Single rooms available for booking :\n");
                        for(w=101;w<151;w++){
                            for(h=0;h!=oldct+1;h++){
                              if(ct[h].roomno<151){
                                if(w==ct[h].roomno){
                                    f=1;break;}}}
                        if(f==0){
                            sg[z]=w;z++;}
                        f=0;
                        }
                        sg[z]='\0';
                        for(h=0;sg[h+1]!='\0';h++)
                            printf("%d,",sg[h]);
                        printf("%d\n",sg[h]);
                        while(t1==0 || t2==0){
                            printf("Enter room no.(101-150): "); scanf("%d",&ctemp.roomno);
                            if(ctemp.roomno<101 || ctemp.roomno>150){
                                printf("Invalid.\n"); t1=0;
                                }
                            else{
                                t1=1;
                                for(j=0;j<oldct;j++){
                                if((ctemp.roomno)==(ct[j].roomno)){
                                    printf("Room already booked.\n");t2=0; break; }
                                else
                                    t2=1;
                                }
                                }
                         }
                }}
                if(strcmp(ctemp.roomtype,"double")==0){
                    if(doubleb==50){
                        printf("All double rooms booked.\n");
                        break;}
                    else{
                        doubleb=doubleb+1;
                        printf("Double rooms available for booking :\n");
                        for(w=201;w<251;w++){
                            for(h=0;h!=oldct+1;h++){
                              if(ct[h].roomno>200 && ct[h].roomno<251){
                                if(w==ct[h].roomno){
                                    f=1;break;}}}
                        if(f==0){
                            db[z]=w;z++;}
                        f=0;
                        }
                        db[z]='\0';
                        for(h=0;db[h+1]!='\0';h++)
                            printf("%d,",db[h]);
                        printf("%d\n",db[h]);
                        while(t1==0 || t2==0){
                        printf("Enter room no.(201-250): "); scanf("%d",&ctemp.roomno);
                        if(ctemp.roomno<201 || ctemp.roomno>250){
                            printf("Invalid.\n"); t1=0;
                        }
                        else{
                            t1=1;
                            for(j=0;j<oldct;j++){
                            if((ctemp.roomno)==(ct[j].roomno)){
                                printf("Room already booked.\n");t2=0; break;}
                            else
                                t2=1;
                                }
                }}
                }}
                if(strcmp(ctemp.roomtype,"deluxe")==0){
                    if(deluxeb==50){
                        printf("All deluxe rooms booked.\n");
                        break;}
                    else{
                        deluxeb=deluxeb+1;
                        printf("Deluxe rooms available for booking :\n");
                        for(w=301;w<351;w++){
                            for(h=0;h!=oldct+1;h++){
                              if(ct[h].roomno>300 && ct[h].roomno<351){
                                if(w==ct[h].roomno){
                                    f=1;break;}}}
                        if(f==0){
                            dlx[z]=w;z++;}
                        f=0;
                        }
                        dlx[z]='\0';
                        for(h=0;dlx[h+1]!='\0';h++)
                            printf("%d,",dlx[h]);
                        printf("%d\n",dlx[h]);
                        while(t1==0 || t2==0){
                        printf("Enter room no.(301-350): "); scanf("%d",&ctemp.roomno);
                            if(ctemp.roomno<301 || ctemp.roomno>350){
                                printf("Invalid.\n"); t1=0;
                            }
                            else{
                                t1=1;
                                for(j=0;j<oldct;j++){
                                if((ctemp.roomno)==(ct[j].roomno)){
                                    printf("Room already booked.\n");t2=0; break;}
                                else
                                    t2=1;
                                    }
                        }}
                    }}
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                 break;
                }
            case 3:{
                ctemp.phno=strtoll(what,&p,10);
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                break;
                }
            case 4:{
                strcpy(ctemp.email,what);
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                break;
                }
            case 5:{
                ctemp.days=atoi(what);
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                break;
                }
            case 6:{
                ctemp.totalamt=atoi(what);
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                break;
                }
            case 7:{
                ctemp.paidamt=atoi(what);
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                break;
                }
            case 8:{
                ctemp.balamt=atoi(what);
                fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                break;
                }
            default:printf("Incorrect option\n"); break;
            }}

        else
            fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                }
        if(flag==0)
                printf("This customer no. does not exist.\n");
        else if(flag==1)
            printf("Record updated.\n");
        }
    fclose(fp);
    fclose(fp1);
    fp=fopen("hoteldb2.txt","w");
    fp1=fopen("hoteltemp.txt","r");
    if(fp==NULL || fp1==NULL){
        printf("Not opening. Please provide the correct file.\n");
    }
    else{
        //printf("Opened\n");
        while(!feof(fp1)){
            if(fscanf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email)!=10)
                break;
            fprintf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
        }
    //fputs("\n",fp);
    fclose(fp);
    fclose(fp1);
    printf("\n");
    //printf("File closed \n");
}}
void removedata()
{
    setcolor(10);
    system("cls");
    FILE *fp;
    FILE *fp1;
    int i,flag=0,oldct,j;
    char what[30];
    struct custm ct[30];
    struct custm ctemp;
    int currb,lineb,tryi;
    int sby;
    int upd;
    char *p;
    fp=fopen("hoteldb2.txt","r");
    fp1=fopen("hoteltemp.txt","w");
    if(fp==NULL || fp1==NULL){
        printf("Not opening. Please provide the correct file.\n");
    }
    else{
        //printf("Opened\n");
        i=0;
        printf("Enter the Customer-no. of the record to delete: ");
        scanf("%d",&sby);
        while(!feof(fp)){
            if(fscanf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email)!=10)
                break;
        if(ctemp.slno==sby){
            printf("Customer record deleted.\n");flag=1;
            if(strcmp(ctemp.roomtype,"single")==0)
                singleb=singleb-1;
            if(strcmp(ctemp.roomtype,"double")==0)
                doubleb=doubleb-1;
            if(strcmp(ctemp.roomtype,"deluxe")==0)
                deluxeb=deluxeb-1;
            }
        else
            fprintf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
                }
        if(flag==0)
                printf("This customer no. does not exist.\n");}
    fclose(fp);
    fclose(fp1);
    fp=fopen("hoteldb2.txt","w");
    fp1=fopen("hoteltemp.txt","r");

    while(!feof(fp1)){
        if(fscanf(fp1,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",&ctemp.slno,ctemp.cname,&ctemp.roomno,ctemp.roomtype,&ctemp.phno,&ctemp.days,&ctemp.totalamt,&ctemp.paidamt,&ctemp.balamt,ctemp.email)!=10)
            break;
        fprintf(fp,"%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",ctemp.slno,ctemp.cname,ctemp.roomno,ctemp.roomtype,ctemp.phno,ctemp.days,ctemp.totalamt,ctemp.paidamt,ctemp.balamt,ctemp.email);
    }
    //fputs("\n",fp);
    fclose(fp);
    fclose(fp1);
    //printf("File closed \n");
}

void roomdata()
{
    setcolor(10);
    system("cls");
    printf("\nRooms occupied:\n");
    printf("\tsingle rooms:%d\n",singleb);
    printf("\tdouble rooms:%d\n",doubleb);
    printf("\tdeluxe rooms:%d\n",deluxeb);
    printf("Rooms available:\n");
    printf("\tsingle rooms:%d\n",singlet-singleb);
    printf("\tdouble rooms:%d\n",doublet-doubleb);
    printf("\tdeluxe rooms:%d\n",deluxet-deluxeb);
    printf("Total rooms : %d\n",total);
    totalb=singleb+doubleb+deluxeb;
    printf("Total rooms booked : %d\n",totalb);
    totala=total-totalb;
    printf("Rooms available for booking: %d\n\n",totala);
}
void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}

