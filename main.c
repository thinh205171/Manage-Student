#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien
{
    int id;
    char name[20];
    char gender[5];
    int age;
    float math, physics, chemistry, GPA;
    char rank[10];
}SV;

void menu()
{
    printf("CHUONG TRINH QUAN LY SINH VIEN C/C++\n");
    printf("*************************MENU**************************\n");
    printf("**  1. Them sinh vien.                               **\n");
    printf("**  2. Cap nhat thong tin sinh vien boi ID.          **\n");
    printf("**  3. Xoa sinh vien boi ID.                         **\n");
    printf("**  4. Tim kiem sinh vien theo ten.                  **\n");
    printf("**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n");
    printf("**  6. Sap xep sinh vien theo ten.                   **\n");
    printf("**  7. Hien thi danh sach sinh vien.                 **\n");
    printf("**  8. Ghi danh sach sinh vien vao file.             **\n");
    printf("**  0. Thoat                                         **\n");
    printf("*******************************************************\n");
    printf("Nhap tuy chon: ");
}

void selection()
{
    printf("\n\nDo you want to continue?\n");
    printf("- Yes, I do. (press 'y', 'Y')\n");
    printf("- No, I don't. (press 'n', 'N')\n");
    printf("- Please clear the screen ! (press 'c', 'C')\n");
}

void Add_Student(SV *p, int n, int m, int id)
{
    int i;
    p = (SV*)realloc(p, n*sizeof(SV));
    printf("Profile of student: \n\n");
    for(i=m;i<n;i++)
    {
        printf("Student %d: \n",i + 1);
        p[i].id = ++id;
        printf("Id: %d\n",p[i].id);
        printf("Name: ");    fflush(stdin);
        scanf("%[^\n]%*c",p[i].name);
        printf("Gender: ");    fflush(stdin);
        scanf("%s",p[i].gender);
        printf("Age: ");     scanf("%d",&p[i].age);
        printf("Math: ");     scanf("%f",&p[i].math);
        printf("Physics: ");     scanf("%f",&p[i].physics);
        printf("Chemistry: ");     scanf("%f",&p[i].chemistry);
        p[i].GPA =(p[i].math + p[i].physics + p[i].chemistry) / 3;
        printf("GPA: %.2f\n",p[i].GPA);
        if(p[i].GPA >= 8 && p[i].GPA <= 10)
            strcpy(p[i].rank,"Excellent");
        else if(p[i].GPA >= 6.5 && p[i].GPA <= 8)
            strcpy(p[i].rank,"Good");
        else if(p[i].GPA >= 4 && p[i].GPA <= 6.5)
            strcpy(p[i].rank,"Normal");
        else if(p[i].GPA <= 4.5)
            strcpy(p[i].rank,"Bad");
        printf("Rank: %s\n",p[i].rank);
        printf("\n");
    }
}

void table(SV *p, int n)
{
    printf("----------------------------------------------------------------------------------------------------\n");
    int i;
    printf("%-5s%-15s%-10s%-8s%-10s%-13s%-13s%-15s%-10s\n","ID", "Name", "Gender", "Age", "Math", "Physics", "Chemistry", "GPA","Rank");
    printf("----------------------------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
        printf("%-5d%-15s%-10s%-8d%-10.2f%-13.2f%-13.2f%-15.2f%-10s\n",p[i].id,p[i].name,p[i].gender,p[i].age,p[i].math,p[i].physics,p[i].chemistry,p[i].GPA,p[i].rank);
    printf("----------------------------------------------------------------------------------------------------\n");
}

void update_by_id(SV *p, int id, int n)
{
    int i, check = 0;
    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            check = 1;
            break;
        }
    }
    if(check == 0)
    {
        printf("No found id %d\n",id);
        return;
    }
    printf("Update data of student has id %d:\n",p[i].id);
    printf("Name: ");    fflush(stdin);
    scanf("%[^\n]%*c",p[i].name);
    printf("Gender: ");    fflush(stdin);
    scanf("%s",p[i].gender);
    printf("Age: ");     scanf("%d",&p[i].age);
    printf("Math: ");     scanf("%f",&p[i].math);
    printf("Physics: ");     scanf("%f",&p[i].physics);
    printf("Chemistry: ");     scanf("%f",&p[i].chemistry);
    p[i].GPA =(p[i].math + p[i].physics + p[i].chemistry) / 3;
    printf("GPA: %.2f\n\n",p[i].GPA);
}

void delete_by_id(SV *p, int id, int n)
{
    int i, check = 0;
    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            check = 1;
            break;
        }
    }
    if(check == 0)
    {
        printf("No found id %d\n",id);
        return;
    }
    int j;
    for(j=i;j<n-1;j++)
        p[j] = p[j+1];
}

void find_by_name(SV *p, int n, char *name)
{
    int i, check = 0;
    for(i=0;i<n;i++)
    {
        if(strcmp(p[i].name,name) == 0)
        {
            printf("%-5s%-15s%-10s%-8s%-10s%-13s%-13s%-15s%-10s\n","ID", "Name", "Gender", "Age", "Math", "Physics", "Chemistry", "GPA","Rank");
            printf("----------------------------------------------------------------------------------------------------\n");
            printf("%-5d%-15s%-10s%-8d%-10.2f%-13.2f%-13.2f%-15.2f%-10s\n",p[i].id,p[i].name,p[i].gender,p[i].age,p[i].math,p[i].physics,p[i].chemistry,p[i].GPA,p[i].rank);
            check = 1;
            break;
        }
    }
    if(check == 0)
        printf("No found %s\n",name);
}

void sort_by_gpa(SV *p, int n)
{
    int i, j;
    SV tmp;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(p[i].GPA < p[j].GPA)
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
}

void sort_by_name(SV *p, int n)
{
    int i, j;
    SV tmp;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(strcmp(p[i].name,p[j].name) > 0)
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
}

void Save(SV *p, int n)
{
    FILE *f = fopen("student.txt","w");
    int i;
    fprintf(f,"%d\n",n);
    for(i=0;i<n;i++)
        fprintf(f,"%d\n%s\n%s\n%d\n%f\n%f\n%f\n%f\n%s\n",p[i].id,p[i].name,p[i].gender,p[i].age,p[i].math,p[i].physics,p[i].chemistry,p[i].GPA,p[i].rank);
    fclose(f);
    printf("Save succesfully\n");
}

int main()
{
    FILE *f = fopen("student.txt","a+");
    int total;
    fscanf(f,"%d",&total);
    printf("Total student: %d\n",total);
    SV *p = (SV*)malloc(total*sizeof(SV));
    int id_f, tuoi, i;
    char n_a_m_e[20], sex[5], hang[10];
    float toan, ly ,hoa, tbinh;
    for(i=0;i<total;i++)
    {
        fscanf(f,"%d\n",&id_f);
        p[i].id = id_f;
        fscanf(f,"%[^\n]%*c",n_a_m_e);
        strcpy(p[i].name,n_a_m_e);
        fscanf(f,"%s",sex);
        strcpy(p[i].gender,sex);
        fscanf(f,"%d",&tuoi);
        p[i].age = tuoi;
        fscanf(f,"%f",&toan);
        fscanf(f,"%f",&ly);
        fscanf(f,"%f",&hoa);
        fscanf(f,"%f",&tbinh);
        p[i].math = toan;
        p[i].physics = ly;
        p[i].chemistry = hoa;
        p[i].GPA = tbinh;
        fscanf(f,"%s",hang);
        strcpy(p[i].rank,hang);
    }
    fclose(f);
    int choice, id, n = total, m, n_tmp = total;
    char c, name[20];
    while(1)
    {
        menu();
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                printf("Enter number of student to add: ");    scanf("%d",&m);
                Add_Student(p,m + n,n,n_tmp);
                n += m;
                n_tmp += m;
                break;
            case 2:
                printf("Enter id to update: ");     scanf("%d",&id);
                printf("\n");
                update_by_id(p,id,n);
                //table(p,n);
                break;
            case 3:
                printf("Enter id to delete: ");     scanf("%d",&id);
                printf("\n");
                delete_by_id(p,id,n);
                --n;
                printf("\n");
                //table(p,n);
                break;
            case 4:
                printf("Enter name to find: ");     fflush(stdin);
                scanf("%[^\n]%*c",name);
                printf("\n");
                find_by_name(p,n,name);
                break;
            case 5:
                sort_by_gpa(p,n);
                printf("Sort by GPA:\n");
                table(p,n);
                break;
            case 6:
                sort_by_name(p,n);
                printf("Sort by Name:\n");
                table(p,n);
                break;
            case 8:
                Save(p,n);
                break;
            case 7:
                table(p,n);
                break;
            default:
                printf("Goodbye\n");
                return 0;
        }
        selection();
        printf("Enter your selection: ");   fflush(stdin);
        scanf("%c",&c);
        printf("\n");
        if(c == 'n' || c == 'N')
            return 0;
        if(c == 'c' || c == 'C')
            system("@cls||clear");
        if(c == 'y' || c == 'Y')
            continue;
        while(c != 'n' && c != 'N' && c != 'c' && c != 'C' && c != 'y' && c != 'Y')
        {
            printf("Error! Please enter again!!\n");
            printf("Enter your selection: ");   fflush(stdin);
            scanf("%c",&c);
            if(c == 'n' || c == 'N')
                return 0;
            if(c == 'c' || c == 'C')
                system("@cls||clear");
        }
    }
    return 0;
}
