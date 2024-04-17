#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int n,m,fa[205],j=0,ans=0;//j已输入的路径数 
string s[205];//保存小区名称 

struct Edge//边表 
{
	int u; 
	int v; 
	int w;//代价 
} edge[205],ed[205];

bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
//快排的依据 
int find(int x)
{
	while (x!=fa[x])
	x=fa[x]=fa[fa[x]];
}
//并查集循环实现模板，查询x的根 
void kruskal()
{
	sort(edge,edge+m,cmp);//对边按权值排序 
	int nn=0;
	for (int i=0;i<m;i++)
	{
		int eu,ev;
		eu=find(edge[i].u);ev=find(edge[i].v);
		if(eu==ev) continue;//若出现两个点已经连通，则跳过这条边 
		ed[j++]=edge[i];
		ans+=edge[i].w;
		fa[ev]=eu;//将两条边的根合并 
		if(j==n-1)break;//满足n-1条边时结束循环 
	}
 } 
 
 void print()//输出模块 
 {
	for(int i=0;i<n-1;i++)
	cout<<"连接"<<s[ed[i].u]<<"和"<<s[ed[i].v]<<"，距离为"<<ed[i].w<<endl;
  } 
  
void in() //输入模块 
{
 	cout<<"请输入小区数量：";cin>>n; 
 	cout<<"请输入已知路径数量：";cin>>m;//n个小区，m个间距 
 	cout<<"请按顺序输入小区名称："<<endl; 
 	for(int i=1;i<=n;i++)
 	{
 		cout<<i<<":";cin>>s[i];
	 }
 	for(int i=1;i<=n;i++) fa[i]=i;
 	cout<<"请输入每条路径端点的两个小区及路径长度(例如小区1到小区3之间距离为4：1 3 4)："<<endl; 
 	for(int i=0;i<m;i++)
 	{
 		int a,b,c;
 		cin>>a>>b>>c;
 	 	if(a<1||a>n||b<1||b>n||c<0)
		{
 			cout<<"输入不合规范，请重新输入这条路径。"<<endl; 
 			i--;
 			continue;
		}
 		edge[i].u=a;
 		edge[i].v=b;
 		edge[i].w=c;
	 }	
}
void sset()//清空 
{
	//清空ans edge ed fa j
	ans=0;j=0;memset(fa,'\0',sizeof(fa)) ;
	memset(&edge,0,sizeof(struct Edge));
	memset(&ed,0,sizeof(struct Edge));
}
void isconnected()//判断是否连通 
{
	if(j<n-1)cout<<"无法连通所有小区。"<<endl;
	else{
		cout<<"最佳方案如下："<<endl;
		print();
		cout<<"煤气管道铺设总长度为"<<ans<<endl; 
	}
 } 
 int main()
 {
 	while(1)
 	{
 		cout<<endl<<"==煤气管道铺设设计系统=="<<endl;
		cout<<"1.开始设计"<<"2.退出系统"<<endl; 
		char op;cin>>op;
		if(op=='2')return 1;
		
		in();
		kruskal();
		isconnected();
		sset();
	 }
 }
