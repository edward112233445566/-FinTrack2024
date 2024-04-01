#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <stdio.h>

// 定義一個結構表示每一筆收入或支出
struct Transaction {
    char type[10];  // 類型：收入或支出
    float amount;   // 金額
    char category[50];  // 類別
    char date[20];  // 日期
};


// 定義一個函數用於輸入和保存交易信息
void addTransaction(struct Transaction transactions[], int *transactionCount) {
    struct Transaction newTransaction;
    printf("請輸入交易類型 (income/expenses): ");
    scanf("%s", newTransaction.type);
    printf("請輸入金額: ");
    scanf("%f", &newTransaction.amount);
    printf("請輸入類別: ");
    scanf("%s", newTransaction.category);
    printf("請輸入日期 (yyyy-mm-dd): ");
    scanf("%s", newTransaction.date);

    // 將新的交易信息添加到數組中
    transactions[*transactionCount] = newTransaction;
    (*transactionCount)++;
    printf("交易已成功添加！\n");
}


// 定義一個函數用於計算並顯示收支統計
void displayStatistics(struct Transaction transactions[], int transactionCount) {
    float totalIncome = 0;
    float totalExpenses = 0;

    printf("\n收支統計:\n");

    // 遍歷所有交易，計算總收入和總支出
    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "income") == 0) {
            totalIncome += transactions[i].amount;
        } else if (strcmp(transactions[i].type, "expenses") == 0) {
            totalExpenses += transactions[i].amount;
        }
    }

    printf("總收入: %.2f\n", totalIncome);
    printf("總支出: %.2f\n", totalExpenses);
    printf("凈收入: %.2f\n", totalIncome - totalExpenses);
}


void saveTransactionsToFile(struct Transaction transactions[], int transactionCount, const char *filename);

// 實現函數
void saveTransactionsToFile(struct Transaction transactions[], int transactionCount, const char *filename) {
    FILE *file = fopen(filename, "wb"); // 以二進制寫入模式打開文件
    if (file == NULL) {
        printf("無法打開文件 %s\n", filename);
        return;
    }

    // 將交易信息寫入文件
    fwrite(transactions, sizeof(struct Transaction), transactionCount, file);

    fclose(file);
    printf("交易信息已成功保存到文件 %s\n", filename);
}
//加密
void encryptData(char *data);

void encryptData(char *data) {
    int i = 0;
    while (data[i] != '\0') {
    // 將字符替換成其後一個字符
        if (data[i] != 'z') {
            data[i] = data[i] + 1;
        } else {
            data[i] = 'a'; // 如果字符是 'z'，則替換成 'a'
        }
        i++;
    }
}


int main() {
     // 驗證密碼
    char password[20];
    printf("請輸入密碼: ");
    scanf("%s", password);

    // 假設密碼是 "password"
    if (strcmp(password, "password") != 0) {
        printf("密碼錯誤，程序退出\n");
        return 1;
    }

    struct Transaction transactions[100]; // 假設最多有100筆交易
    int transactionCount = 0;

    int choice;
    do {
        printf("\n選擇操作:\n");
        printf("1. 記錄新的交易\n");
        printf("2. 顯示收支統計\n");
        printf("3. 退出\n");
        printf("請輸入選擇: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(transactions, &transactionCount);
                break;
            case 2:
                displayStatistics(transactions, transactionCount);
                break;
            case 3:
                printf("退出程序\n");
                // 可以在這裡保存交易信息到文件，然後退出程序
                break;
            default:
                printf("無效的選擇\n");
        }
    } while (choice != 3);

    return 0;
}

