

#include <stdio.h>
#include <conio.h>

static char c[512];
int main(int argc, char* argv[])
{
	printf("\n��������������(�ļ���)д�뵽vhd��ʽ�ļ�����������������\n");
	printf("1.���������ݵĴ�СӦ��Ϊ 512 bytes\n");
	printf("2.��һ������ 446 bytes������\n\n");
	printf("Version 1.0.0\n");
	printf("Usage: mbr [SourceFile] [DestVHD]\n");
	

	FILE* fp1 = NULL;
	FILE* fp2 = NULL;

	if (argc > 2)
	{
		fp1 = fopen(argv[1], "rb+");
		if (fp1 == NULL)
		{
			printf("��Դ�ļ�(%s)ʧ��!\n", argv[1]);
			printf("Press Enter to exit...\n");
			getchar();
			return 0;
		}

		// "G:\\VirtualBox VMs\\dos2\\dos2.vhd", "rb+");
		fp2 = fopen(argv[2], "rb+");
		if (fp2 == NULL)
		{
			printf("��Ŀ���ļ�(%s)ʧ��!\n", argv[2]);
			fclose(fp1);
			printf("Press Enter to exit...\n");
			getchar();
			return 0;
		}

		fread(c, 512, 1, fp1);
		fseek(fp2, 0, SEEK_SET);
		fwrite(c, 512, 1, fp2);

		fclose(fp1);
		fclose(fp2);
		printf("\nDone!\n");
	}
	else
	{
		printf("\n��������, �μ�\nUsage: mbr [SourceFile] [DestVHD]\n\n");
		printf("Press Enter to exit...\n");
		getchar();
	}

	return 0;
}