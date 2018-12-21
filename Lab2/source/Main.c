#include<stdlib.h>
#include<stdio.h>

struct clientData
{
	int acctNum;
	char lastName[15];
	char firstName[10];
	double balance;
};
int main(void)
{
	FILE *pRead, *pWrite;
	FILE *cfPtr;
	int cnt = 0;
	int i, j;
	struct clientData client = { 0,"","",0.0 };
	i= fopen_s(&pRead, "C://Users/User/Desktop/c.code/credit.txt", "r");
	if (NULL== pRead )
	{
		return 0;
	}
	j = fopen_s(&pWrite, "C://Users/User/Desktop/c.code/credit_bin.txt", "wb");
	if ( NULL==pWrite )
	{
		fclose(pRead);
		return 0;
	}
	while (!feof(pRead))
	{
		fscanf_s(pRead, "%d%s%s%lf", &client.acctNum, client.lastName,16 ,client.firstName,11, &client.balance);
		fwrite(&client, sizeof(struct  clientData), 1, pWrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
	}
	fclose(pRead);
	fclose(pWrite);
	printf("已讀取文字檔的ASCII資料，並轉存成二進制資料檔案\n\n");
	system("pause");
	printf("\n讀取二進制資料檔案，並格式化輸出如下:\n");
	int a  = fopen_s(&cfPtr, "C://Users/User/Desktop/c.code/credit_bin.txt", "rb");
	if (a != 0)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		while (cnt>0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
		fclose(cfPtr);
	}
	system("pause");
	return 0;
}