#include <windows.h>
#include <stdio.h>

int wmain(int argc, wchar_t *argv[])
{
    /*
		ɾ���ļ� api.exe -d �ļ�·��
		�����ļ� api.exe -c ·��1 ·��2
		�ƶ�/�������ļ� api.exe -m ·��1 ·��2
	*/

    if (argc == 3 && 0 == lstrcmp(L"-d", argv[1]))
    { // ���������Ƿ��� �ڶ�������Ϊ-d ���� �����в����ĸ���Ϊ3  �ú�������������ֵ����ΪLPCWSTR

        if (!DeleteFile(argv[2]))
        { //unicode��ʱ�� ���յ�ֵΪ LPCWSTR
            printf("ɾ��ʧ�� \n");
        }
        else
        {
            printf("ɾ���ɹ� \n");
        }
    }
    else if (argc == 4 && 0 == lstrcmp(L"-c", argv[1]))
    {
        if (!CopyFile(argv[2], argv[3], true))
        { //����������Ϊtrue��ô�ļ�����Ѿ������򲻽��и���
            //����ʧ�ܣ�����һ�ֿ����Ǵ����ļ�ͬ��,copyfile ����ֵΪ0x50
            if (getchar() == 'y')
            {
                if (!CopyFile(argv[2], argv[3], false))
                { //����������Ϊfalse��ô�ļ�����Ѿ�������ֱ�Ӹ���
                    printf("�ļ�����ʧ��");
                }
                else
                {
                    printf("�ļ����Ƴɹ�");
                }
            }
        }
        else
            printf("�ļ����Ƴɹ�! \n");
    }
    else if (argc == 4 && 0 == lstrcmp(L"-m", argv[1]))
    {
        //�����ƶ�/�������ļ��Ĳ���
        if (!MoveFile(argv[2], argv[3]))
        { //movefile �� copyfile api ��������������һ�����÷�Ҳ����
            printf("�ļ��ƶ�ʧ��! \n");
        }
        else
        {
            printf("�ļ��ƶ��ɹ�! \n");
        }
    }
    else
    {
        printf("��������! ����������");
    }

    system("pause");
    return 0;
}