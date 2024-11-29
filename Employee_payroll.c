#include <stdio.h>
#include <string.h>

struct date {
    int date;
    int month;
    int year;
};

struct payroll {
    int w_days;
    int l_days;
    char con[20];
    char pos[20];
    char dw[20];
    int month;
    int s_m;
    int man_con;
    int sup_con;
    int man_pos;
    int sup_pos;
    int dw_con;
    int dw_ws;
};

struct emp {
    int id;
    char name[50];
    int dep_id;
    struct date j_d;
    int designation;
    int choice;
    char a[20];
    char b[20];
    char c[20];
    char address[50];
    int mobile_no;
};

struct department {
    char dept_id[10];
    int dept;
    char sup_id[10];
    char man_id[10];
    int choice1;
    char staf_id[10];
    char description[80];
};

void department(struct emp *p, FILE *fp);
void payroll(struct department *pr, FILE *fp);
void emp();
void read();
void read_specific();
void calculate_salary();

int main() {
    int choice;
begin:
    printf("\nENTER THE CHOICE:\n1.TO ENTER DETAILS THE EMPLOYEE\n2.TO DISPLAY ALL DETAILS OF THE EMPLOYEE\n3.TO DISPLAY SPECIFIC EMPLOYEE DETAILS\n4.TO CALCULATE SALARY FOR CURRENT MONTH\n5.EXIT\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            emp();
            goto begin;
        case 2:
            read();
            goto begin;
        case 3:
            read_specific();
            goto begin;
        case 4:
            calculate_salary();
            goto begin;
        case 5:
            return 0;
    }
}

void emp() {
    struct emp e;
    FILE *fp = fopen("emp_detail.txt", "a+");
    if (fp == NULL) {
        printf("Error in opening file");
        return;
    }

    strcpy(e.a, "MANAGER");
    strcpy(e.b, "SUPERVISOR");
    strcpy(e.c, "WORKING STAFF");

    printf("\n\t\tENTER EMPLOYEE DETAILS");
    fprintf(fp, "\nEMPLOYEE DETAILS");
    printf("\nENTER THE ID: ");
    scanf("%d", &e.id);
    fprintf(fp, "\nID: %d", e.id);
    printf("\nENTER THE NAME: ");
    scanf("%s", e.name);
    fprintf(fp, "\nName: %s", e.name);
    printf("\nENTER THE JOIN DATE (date month year): ");
    scanf("%d %d %d", &e.j_d.date, &e.j_d.month, &e.j_d.year);
    fprintf(fp, "\nJoin Date: %d/%d/%d", e.j_d.date, e.j_d.month, e.j_d.year);
    printf("\nENTER THE ADDRESS: ");
    scanf("%s", e.address);
    fprintf(fp, "\nAddress: %s", e.address);
    printf("\nENTER THE PHONE NO: ");
    scanf("%d", &e.mobile_no);
    fprintf(fp, "\nPhone No: %d", e.mobile_no);
    department(&e, fp);

    fclose(fp);
}

void department(struct emp *p, FILE *fp) {
    struct department dep;
    char w[20], u[20], k[20];
    strcpy(w, "Control_panel");
    strcpy(u, "Molding");
    strcpy(k, "Package");

    printf("\nENTER THE DEPARTMENT ID: ");
    scanf("%s", dep.dept_id);
    fprintf(fp, "\nDepartment ID: %s", dep.dept_id);

begin:
    printf("\nCHOOSE THE CORRECT DEPARTMENT\n1. CONTROL PANEL\n2. MOLDING\n3. PACKAGE\nENTER THE NAME OF THE DEPARTMENT OF EMPLOYEE: ");
    scanf("%d", &dep.dept);

    if (dep.dept == 1) {
        printf("\nNAME OF THE DEPARTMENT: %s", w);
        fprintf(fp, "\nDepartment: %s", w);
    } else if (dep.dept == 2) {
        printf("\nNAME OF THE DEPARTMENT: %s", u);
        fprintf(fp, "\nDepartment: %s", u);
    } else if (dep.dept == 3) {
        printf("\nNAME OF THE DEPARTMENT: %s", k);
        fprintf(fp, "\nDepartment: %s", k);
    } else {
        printf("\nEnter a valid department");
        goto begin;
    }

    printf("\n1. MANAGER\n2. SUPERVISOR\n3. WORKING STAFF\nENTER THE CHOICE: ");
    scanf("%d", &dep.choice1);

begin1:
    switch (dep.choice1) {
        case 1:
            printf("DESIGNATION=%s", p->a);
            printf("\nENTER THE MANAGER ID: ");
            scanf("%s", dep.man_id);
            fprintf(fp, "\nDesignation: %s", p->a);
            fprintf(fp, "\nManager ID: %s", dep.man_id);
            break;
        case 2:
            printf("DESIGNATION=%s", p->b);
            printf("\nENTER THE SUPERVISOR ID: ");
            scanf("%s", dep.sup_id);
            fprintf(fp, "\nDesignation: %s", p->b);
            fprintf(fp, "\nSupervisor ID: %s", dep.sup_id);
            break;
        case 3:
            printf("DESIGNATION=%s", p->c);
            printf("\nENTER THE STAFF ID: ");
            scanf("%s", dep.staf_id);
            fprintf(fp, "\nDesignation: %s", p->c);
            fprintf(fp, "\nStaff ID: %s", dep.staf_id);
            break;
        default:
            printf("ENTER THE CORRECT DESIGNATION");
            goto begin1;
    }

    payroll(&dep, fp);
    printf("\nENTER THE DESCRIPTION OF THE DEPARTMENT: ");
    scanf("%s", dep.description);
    fprintf(fp, "\nDescription: %s", dep.description);
}

void payroll(struct department *pr, FILE *fp) {
    int man_con = 40000, sup_con = 30000, man_pos = 35000, sup_pos = 25000, dw_con = 20000;
    struct payroll roll;

    strcpy(roll.con, "CONSOLIDATED");
    strcpy(roll.pos, "PAY OF SCALE");
    strcpy(roll.dw, "DAILY WAGES");

    printf("ENTER THE DAYS WORKED: ");
    scanf("%d", &roll.w_days);
    fprintf(fp, "\nDays Worked: %d", roll.w_days);

choi:
    printf("ENTER THE MONTH: ");
    scanf("%d", &roll.month);

    switch (roll.month) {
        case 1:
            roll.l_days = 31 - roll.w_days;
            break;
        case 2:
            roll.l_days = 29 - roll.w_days;
            break;
        case 3:
            roll.l_days = 30 - roll.w_days;
            break;
        case 4:
            roll.l_days = 31 - roll.w_days;
            break;
        case 5:
            roll.l_days = 30 - roll.w_days;
            break;
        case 6:
            roll.l_days = 31 - roll.w_days;
            break;
        case 7:
            roll.l_days = 30 - roll.w_days;
            break;
        case 8:
            roll.l_days = 31 - roll.w_days;
            break;
        case 9:
            roll.l_days = 30 - roll.w_days;
            break;
        case 10:
            roll.l_days = 31 - roll.w_days;
            break;
        case 11:
            roll.l_days = 30 - roll.w_days;
            break;
        case 12:
            roll.l_days = 31 - roll.w_days;
            break;
        default:
            printf("Enter the correct month");
            goto choi;
    }

    printf("Leave days = %d", roll.l_days);
    fprintf(fp, "\nLeave Days: %d", roll.l_days);

    if (pr->choice1 == 1) {
        printf("\nSALARY MODE:\n1. CONSOLIDATED\n2. PAY OF SCALE\nENTER THE SALARY MODE: ");
        scanf("%d", &roll.s_m);
        switch (roll.s_m) {
            case 1:
                roll.man_con = man_con - (700 * roll.l_days);
                printf("CONSOLIDATED = %d", roll.man_con);
                fprintf(fp, "\nSalary Mode: %s", roll.con);
                fprintf(fp, "\nSalary: %d", roll.man_con);
                break;
            case 2:
                roll.man_pos = (man_pos * 10 / 100) - (300 * roll.l_days);
                printf("PAY OF SCALE FOR MANAGER: %d", roll.man_pos * 30);
                fprintf(fp, "\nSalary Mode: %s", roll.pos);
                fprintf(fp, "\nSalary: %d", roll.man_pos * 30);
                break;
        }
    } else if (pr->choice1 == 2) {
        printf("\nSALARY MODE:\n1. CONSOLIDATED\n2. PAY OF SCALE\nENTER THE SALARY MODE: ");
        scanf("%d", &roll.s_m);
        switch (roll.s_m) {
            case 1:
                roll.sup_con = sup_con - (500 * roll.l_days);
                printf("CONSOLIDATED = %d", roll.sup_con);
                fprintf(fp, "\nSalary Mode: %s", roll.con);
                fprintf(fp, "\nSalary: %d", roll.sup_con);
                break;
            case 2:
                roll.sup_pos = (sup_pos * 10 / 100) - (300 * roll.l_days);
                printf("PAY OF SCALE: %d", roll.sup_pos * 30);
                fprintf(fp, "\nSalary Mode: %s", roll.pos);
                fprintf(fp, "\nSalary: %d", roll.sup_pos * 30);
                break;
        }
    } else {
        printf("\nSALARY MODE:\n1. CONSOLIDATED\n2. DAILY WAGES\nENTER THE SALARY MODE: ");
        scanf("%d", &roll.s_m);
        switch (roll.s_m) {
            case 1:
                roll.dw_con = dw_con - (300 * roll.l_days);
                printf("CONSOLIDATED = %d", roll.dw_con);
                fprintf(fp, "\nSalary Mode: %s", roll.con);
                fprintf(fp, "\nSalary: %d", roll.dw_con);
                break;
            case 2:
                roll.dw_ws = (dw_con * 10 / 100) - (200 * roll.l_days);
                printf("DAILY WAGES: %d", roll.dw_ws * 30);
                fprintf(fp, "\nSalary Mode: %s", roll.dw);
                fprintf(fp, "\nSalary: %d", roll.dw_ws * 30);
                break;
        }
    }
}

void read() {
    FILE *fp = fopen("emp_detail.txt", "r");
    if (fp == NULL) {
        printf("Error in opening file");
        return;
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void read_specific() {
    FILE *fp = fopen("emp_detail.txt", "r");
    if (fp == NULL) {
        printf("Error in opening file");
        return;
    }

    int emp_id;
    char dept_id[10];
    printf("ENTER EMPLOYEE ID: ");
    scanf("%d", &emp_id);
    printf("ENTER DEPARTMENT ID: ");
    scanf("%s", dept_id);

    char buffer[1000];
    int found_emp = 0;
    int id = -1;
    char dept[10];

    while (fgets(buffer, 1000, fp) != NULL) {
        if (sscanf(buffer, "ID: %d", &id) == 1 && id == emp_id) {
            found_emp = 1;
        }

        if (found_emp) {
            printf("%s", buffer);
            if (sscanf(buffer, "Department ID: %s", dept) == 1 && strcmp(dept, dept_id) == 0) {
                while (fgets(buffer, 1000, fp) != NULL && !strstr(buffer, "EMPLOYEE")) {
                    printf("%s", buffer);
                }
                fclose(fp);
                return;
            }
        }
    }

    printf("Employee with ID %d and Department ID %s not found.\n", emp_id, dept_id);
    fclose(fp);
}

void calculate_salary() {
    FILE *fp = fopen("emp_detail.txt", "r");
    if (fp == NULL) {
        printf("Error in opening file");
        return;
    }

    int emp_id;
    char dept_id[10];
    printf("ENTER EMPLOYEE ID: ");
    scanf("%d", &emp_id);
    printf("ENTER DEPARTMENT ID: ");
    scanf("%s", dept_id);

    char buffer[1000];
    int found_emp = 0;
    int id = -1;
    char dept[10];
    int choice1 = 0;

    struct payroll roll;
    struct department pr;

    while (fgets(buffer, 1000, fp) != NULL) {
        if (sscanf(buffer, "ID: %d", &id) == 1 && id == emp_id) {
            found_emp = 1;
        }

        if (found_emp) {
            if (sscanf(buffer, "Department ID: %s", dept) == 1 && strcmp(dept, dept_id) == 0) {
                while (fgets(buffer, 1000, fp) != NULL && !strstr(buffer, "EMPLOYEE")) {
                    if (sscanf(buffer, "Designation: MANAGER") == 0) {
                        choice1 = 1;
                    } else if (sscanf(buffer, "Designation: SUPERVISOR") == 0) {
                        choice1 = 2;
                    } else if (sscanf(buffer, "Designation: WORKING STAFF") == 0) {
                        choice1 = 3;
                    }
                }
                break;
            }
        }
    }

    fclose(fp);

    if (found_emp) {
        pr.choice1 = choice1;
        payroll(&pr, fp);
    } else {
        printf("Employee with ID %d and Department ID %s not found.\n", emp_id, dept_id);
    }
}
