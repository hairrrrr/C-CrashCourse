#define _CRT_SECURE_NO_WARNINGS

#include"worker.h"

// 交换两个字符串数组
static void swap(char* str1, char* str2)
{
	char tmp[15];
	strcpy(tmp, str1);
	strcpy(str1, str2);
	strcpy(str2, tmp);
}

/*输入函数，完成将键盘输入的职工数据写入磁盘*/
void input_workers()
{
	int i;
	struct_worker worker;			
	FILE* fp;

	system("cls");/*清屏*/

	if ((fp = fopen("d:\\file1.txt", "wb")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\n\t请输入职工人数:");
	scanf("%d", &worker_cnt); /*输入职工人数*/
	for (i = 0; i < worker_cnt; i++)		
	{
		printf("\n\t请输入第%d名职工信息:\n", i + 1);
		printf("\t职工号:");
		scanf("%s", worker.jobNo);
		printf("\t姓名:");
		scanf("%s", worker.name);
		printf("\t性别:");
		scanf("%s", worker.gender);
		printf("\t职务:");
		scanf("%s", worker.position);
		printf("\t电话:");
		scanf("%s", worker.tel);

		fwrite(&worker, sizeof(struct_worker), 1, fp);
	}
	fclose(fp);

	printf("\n\tpress any key to continue...");
	getchar();
	getchar();
}


/*显示函数，完成将文件中的职工数据显示在屏幕上*/
void list_workers(){							
	struct_worker worker;			
	FILE* fp;
	int cnt = worker_cnt;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "rb")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\n\n\n\t职工号\t姓名\t性别\t职务\t电话\n\n");
	
	while (cnt-- && (fread(&worker, sizeof(struct_worker), 1, fp) != 0))
		printf("\t%s  \t%s \t%s \t%s \t%s\n", worker.jobNo, worker.name, worker.gender, worker.position, worker.tel);
	
	fclose(fp);
	printf("\n\tpress any key to continue...");
	getchar(); // 接受输入 2 后敲下的回车
	getchar();
}


/*追加函数，完成将键盘上输入的职工数据追加到文件中*/
void append_workers()			
{
	int i, cnt;
	struct_worker worker;
	FILE* fp;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "ab")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\t请输入追加人数:");
	scanf("%d", &cnt);
	
	for (i = 0; i < cnt; i++)
	{
		printf("\n\t职工号:");
		scanf("%s", worker.jobNo);
		printf("\t姓名:");
		scanf("%s", worker.name);
		printf("\t性别:");
		scanf("%s", worker.gender);
		printf("\t职务:");
		scanf("%s", worker.position);
		printf("\t电话:");
		scanf("%s", worker.tel);

		fwrite(&worker, sizeof(struct_worker), 1, fp);
	}
	
	worker_cnt += cnt;
	fclose(fp);

	printf("\n\tappend success! press any key to continue...");
	getchar(); 
	getchar();
}


/*排序函数，完成对文件中的职工数据按职工号排序并显示在屏幕上*/
void sort_workers(){
	int i, j;
	struct_worker workers[WORKER_MAX];	
	struct_worker tmp;
	FILE* fp;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "rb+")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if (fread(workers, sizeof(struct_worker), worker_cnt, fp) != worker_cnt)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < worker_cnt - 1; i++)
	{
		for (j = i; j < worker_cnt - 1 - i; j++)
		{
			
			if (strcmp(workers[j].jobNo, workers[j + 1].jobNo) > 0)
			{
				swap(workers[j].jobNo, workers[j + 1].jobNo);
				swap(workers[j].gender, workers[j + 1].gender);
				swap(workers[j].name, workers[j + 1].name);
				swap(workers[j].position, workers[j + 1].position);
				swap(workers[j].tel, workers[j + 1].tel);
			}
		}
	}
	
	
	fseek(fp, 0L, SEEK_SET); // 将文件指针置于文件头，重新开始写
	fwrite(workers, sizeof(struct_worker), worker_cnt, fp);

	printf("\n\n\n\t按职工排序:\n");
	printf("\n\t职工号\t姓名\t性别\t职务\t电话\n\n");
	for (i = 0; i < worker_cnt; i++)
		printf("\t%s\t%s\t%s\t%s\t%s\n", workers[i].jobNo, workers[i].name, workers[i].gender, workers[i].position, workers[i].tel);
	
	fclose(fp);
	printf("\n\tpress any key to continue...");
	getchar();		
	getchar();
}


/*查询职工 */
void inquiry_worker()         
{	
	int flg = 0;
	struct_worker worker[WORKER_MAX];
	char tar_name[15];
	FILE* fp;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "rb")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\n\t请输入职工的职工号:");
	scanf("%s", tar_name);

	if (fread(worker, sizeof(struct_worker), worker_cnt, fp) != worker_cnt)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < worker_cnt; i++) {

		if (strcmp(tar_name, worker[i].name) == 0)
		{
			printf("\n\n\n\t职工号\t姓名\t性别\t职务\t电话\n\n");
			printf("\t%s\t%s\t%s\t%s\t%s\n", worker[i].jobNo, worker[i].name, worker[i].gender, worker[i].position, worker[i].tel);
			flg = 1;
			break;
		}
	}

	if (flg == 0)
		printf("该职工不存在！");

	fclose(fp);

	printf("\n\tpress any key to continue...");
	getchar();
	getchar();
}


/*删除函数，完成将文件中的职工数据删除*/
void delete_worker()            
{
	int i, j, flg = 0;
	struct_worker workers[WORKER_MAX], del_jobNo[15];
	FILE* fp;

	system("cls");

	if ((fp = fopen("d:\\file1.txt", "rb+")) == NULL)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("\n\n 请输入要删除职工的职工号:  ");
	scanf("%s", del_jobNo);
	
	if (fread(workers, sizeof(struct_worker), worker_cnt, fp) != worker_cnt)
	{
		printf("error in func: %s line: %d %s: \n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	
	for (i = 0; i < worker_cnt; i++)
		if (strcmp(workers[i].jobNo, del_jobNo) == 0)
		{
			flg = 1;
			break;
		}
			

	if (flg == 0)
		printf("该职工不存在！");
	else
	{
		for (j = i; j < worker_cnt - 1; j++) 
		{
			strcpy(workers[j].jobNo, workers[j + 1].jobNo);
			strcpy(workers[j].gender, workers[j + 1].gender);
			strcpy(workers[j].name, workers[j + 1].name);
			strcpy(workers[j].position, workers[j + 1].position);
			strcpy(workers[j].tel, workers[j + 1].tel);
		}
		worker_cnt--;

		fseek(fp, 0L, SEEK_SET);
		fwrite(workers, sizeof(struct_worker), worker_cnt, fp);

		printf("删除成功！");
	}

	fclose(fp);
	getchar();
	getchar();
}


int main(void)			/*主函数，完成程序菜单的显示并调用以上各函数*/
{
	int choice;
	do
	{
		system("cls");	/*清屏*/
		printf("\n\n\n\n\n\t\t\t\t\t Personnel File Management System\n");	/*显示程序菜单*/
		printf("\n\n\t\t\t\t\t*********************************\n\n");
		printf("\t\t\t\t\t\t1----输入职工信息\n");
		printf("\t\t\t\t\t\t2----显示职工信息\n");
		printf("\t\t\t\t\t\t3----追加职工信息\n");
		printf("\t\t\t\t\t\t4----排序职工信息\n");
		printf("\t\t\t\t\t\t5----查询职工信息\n");
		printf("\t\t\t\t\t\t6----删除职工信息\n");
		printf("\t\t\t\t\t\t0----退出\n");
		printf("\n\t\t\t\t\t*********************************\n");
		printf("\n\t\t\t请选择:");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:	input_workers();    break;		/*调用输入函数*/
			case 2:	list_workers();		break;		/*调用显示函数*/
			case 3:	append_workers();   break;		/*调用追加函数*/
			case 4:	sort_workers();		break;		/*调用排序函数*/
			case 5:	inquiry_worker();	break;		/*调用查询函数*/
			case 6:	delete_worker();	break;		/*调用删除函数*/
			case 0:	exit(0);						/*结束程序的运行*/
		}
	} while (choice != 0);
}


