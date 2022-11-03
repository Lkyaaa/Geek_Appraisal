#include<stdio.h>
#include<string.h>
//定义哈夫曼树结构体
typedef struct {
	int weight;        
   	int parents;      
	int left;
	int right;
	
}Tree;
//定义哈夫曼编码结构体
typedef struct{
	int num;
	int bit[100];
	
}Code;


int n;//定义输入字母的种类数
Tree huffnode[100];//哈夫曼树结构体数组
Code huffcode[100];//哈夫曼编码结构体数组
char shouji[100]={0};//收集输入字符串的数组
int tongji[26]={0};//统计各字母个数的数组
char word[26]="abcdefghijklmnopqrstuvwxyz";//检索小写字母数组
char WORD[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//检索大写字母数组

//子函数：收集输入字符，统计各字母个数及字母种类数
void zifufunction(void){
	scanf("%s",shouji);
	//统计各字母个数
	for(int i=0;i<26;i++){
		for(int j=0;j<strlen(shouji);j++){
			if(shouji[j]==word[i]||shouji[j]==WORD[i])
			{tongji[i]+=1;
		}
		
	}
		printf("The number of %c is %d\n",word[i],tongji[i]);
		
	}
	
	//统计输入字母的种类数
	for(int i=0;i<26;i++){
		if(tongji[i]!=0){
			n++;
		}
		
	}
	printf("The letter count is %d\n",n);

}

//子函数：构造哈夫曼树
void gouzaofunction(void){
    int i,j,min1,min2,x1,x2;//定义变量min1,min2为分别weight中最小的和次小的两个数；x1,x2分别为min1,min2对应的序号数
    //哈夫曼树的初始化
	for(i=1;i<2*n;i++)
	{
		huffnode[i].weight=0;
		huffnode[i].parents=-1;
		huffnode[i].left=-1;
		huffnode[i].right=-1;}
		
		//将储存各字母个数的数组中的非零值按顺序赋值给权重
		for(int i=0,j=1;i<26;i++){
		if(tongji[i]!=0){
		huffnode[j].weight=tongji[i];
		j++;
		}
		else if(tongji[i]==0){
			j=j;
				}
	}

        //构造哈夫曼树
			for(i=1;i<n;i++){
			min1=10000;
			min2=10000;
			x1=0;
			x2=0;
			for(j=1;j<n+i;j++){
				if(huffnode[j].parents==-1&&huffnode[j].weight<min1)//加入parents==-1条件，剔除已经找到父节点的子节点
				{min2=min1;   
				 x2=x1;      //当min1有更小值时，把原min1,x1赋值给min2,x2，保证min1为最小，同时更新次小值
				 min1=huffnode[j].weight;
				 x1=j;}
				else if(huffnode[j].parents==-1&&huffnode[j].weight<min2)
				{min2=huffnode[j].weight;
				x2=j;}
		        }
		       huffnode[x1].parents=n+i; //最小值对应的父节点序号
			   huffnode[x2].parents=n+i;//次小值对应的夫节点序号
			   huffnode[n+i].weight=huffnode[x1].weight+huffnode[x2].weight;//父节点值
			   huffnode[n+i].left=x1;//父节点的左子节点序号
			   huffnode[n+i].right=x2;}//父节点的右子节点序号，这里保证了权值低放左边，权值高放右侧
		}
		
//子函数：输出哈夫曼树	
void shuchu1function(void){
	printf("        count       weight      parents       left         right\n");
	for(int i=1;i<2*n;i++){
		printf("%11d%13d%13d%13d%13d\n",i,huffnode[i].weight,huffnode[i].parents,huffnode[i].left,huffnode[i].right);
	}
} 


//子函数：构造每个字母的哈夫曼编码
void bianmafunction(void){
    Code cd;//创建一个临时结构体数组
	int i,j,c,p;
	//自下而上搜索父节点
	for(i=1;i<=n;i++)
	{c=i;
	 cd.num=n;
	 p=huffnode[c].parents;
	 while(p!=-1){
	 	if(huffnode[p].left==c)//左侧编码为0，右侧编码为1
	 	cd.bit[cd.num]=0;
	 	else cd.bit[cd.num]=1;
	 	cd.num--;//从右向左储存编码
	 	c=p;
	 	p=huffnode[c].parents;
	 	
	 }
	 //将临时存储的编码赋值给哈夫曼编码结构体数组
		for(j=cd.num+1;j<=n;j++){
			huffcode[i].bit[j]=cd.bit[j];
			huffcode[i].num=cd.num;
			
		}
		
		
		
	}
	
	
}

//子函数：输出各字母的哈夫曼编码；
void shuchu2function(void)
{for(int i=1;i<=n;i++)
{for(int j=huffcode[i].num+1;j<=n;j++){
printf("%d",huffcode[i].bit[j]);	
	
	
}printf("\n");
}
}

//子函数：输出整个字符串的哈夫曼编码
void shuchu3function(void){
	printf("The huffmancode of shouji is:");
	//遍历每一个字母
	for(int i=0;i<strlen(shouji);i++){
	  int m=1;int k=0;
		for(int j=0;j<26;j++){
			if(shouji[i]==word[j]||shouji[i]==WORD[j])
			k=j;  //找到该字母对应在统计字母个数的数组中的第几位              
			 else if(shouji[i]!=word[j]||shouji[i]!=WORD[j])                  
				k=k;			   
							   
							   
							   }
             for(int r=0;r<k;r++){
              if(tongji[r]!=0)
			  m++;   //计算该字母是第几个非零频率的字母，那么该字母就对应第几个哈夫曼编码
			  else if(tongji[r]==0)
			  m=m;}
			   for(int o=huffcode[m].num+1;o<=n;o++){
printf("%d",huffcode[m].bit[o]);   }//打印该字母对应的哈夫曼编码，并回到第一个for循环继续检索下一个字母        	
           	

	              }	printf("\n");
	}
	
	//子函数：计算wpl的值
	void WPLfunction(void){
		int WPL=0;
		//遍历每一个叶子节点
		for(int i=1;i<=n;i++){
			int c,j,p;
			c=i;
			j=0;
			p=huffnode[c].parents;
			while(p!=-1){
				j++;
				c=p;
				p=huffnode[c].parents;
				
				
			}//计算该叶子节点的带权路径长度
			WPL=WPL+j*huffnode[i].weight;//累加每一个叶子节点的带权路径长度，就是整个树的带权路径长度
			
		
		}
		printf("WPL=%d\n",WPL);
		
		
		
		
		
	}
	
	
	//主函数：执行子函数内容
	int main(void){
        zifufunction();
		gouzaofunction();
	    shuchu1function();
		bianmafunction();
		shuchu2function();
		shuchu3function();
		WPLfunction();
		return 0;
	}	
		