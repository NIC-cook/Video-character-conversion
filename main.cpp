#include<stdio.h>
/* 包含putchar()
    相关文件操作
	fopen()打开文件 
	feof()判断文件到结尾
	更多查看stdio.h 
*/
#include<stdlib.h>
/*
	常用的system()
	sand() 
	与rand() 
*/
#include<time.h>
/*
	用系统时间初始化获取随机数 
*/
#include<windows.h>
FILE *fp=NULL;//文件结构体指针 
int main()
{
	char name[]="ASCII-BadApple 0007.txt";
	char a[]="0007";
	int i,j,n=1,p,q,ff=0;
	for(i=7;i<1301;i++){ 
	
	//时间轴定位
            for(p=10,q=0;q<4;q++)
            {
                  if(i<10&&q==1)break;
                  
                  else if(i<100&&q==2)break;

                  else if(i<1000&&q==3)break;
                  
                  else if(i<10000&&q==4)break;

                  else

                  {

                       a[q]=i%p/(p/10)+48;

                       p*=10; 

                  }

            }

            //重命名

            for(p=0;p<q;p++)

                  name[18-p]=a[p];
	
		fp=fopen(name,"r");
		/*
		fopen()打开和源码相同文件夹下的1.txt文件
		权限文r，只读
		*/
		if(NULL==fp)//判断这文件是否打开成功
		{
			printf("文件打开失败！原因是打开和同一文件夹",
			"下不存在该文件或这个文件已经被系统打开\n");
			return 1;//返回1,和最后的return 0;进行区分 
		}
		srand((unsigned int)time(NULL));//初始化随机数种子使用系统时间
	    char ch; 
		while(!feof(fp))//判断文件是否到结尾feof判断文件到结尾后返回假
		{
			ch=fgetc(fp);//文件之中读取一个字符
			//Sleep(rand()%1+1);//延迟1~100ms显示可以看到效果 
			putchar(ch);//将字符打印到屏幕 
		}
		fclose(fp);//关闭文件 
		//Sleep(rand()%1+1);//延迟1~100ms显示可以看到效果 
		//for(int ff=0;ff<1000;ff++){printf("\n");}
		if(ff==0){
			system("cls");//清屏
			ff=0;
			}
		else
			ff++;
		
	} 
	return 0;	
} 
