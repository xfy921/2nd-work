#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int n,m,fa[205],j=0,ans=0;//j�������·���� 
string s[205];//����С������ 

struct Edge//�߱� 
{
	int u; 
	int v; 
	int w;//���� 
} edge[205],ed[205];

bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
//���ŵ����� 
int find(int x)
{
	while (x!=fa[x])
	x=fa[x]=fa[fa[x]];
}
//���鼯ѭ��ʵ��ģ�壬��ѯx�ĸ� 
void kruskal()
{
	sort(edge,edge+m,cmp);//�Ա߰�Ȩֵ���� 
	int nn=0;
	for (int i=0;i<m;i++)
	{
		int eu,ev;
		eu=find(edge[i].u);ev=find(edge[i].v);
		if(eu==ev) continue;//�������������Ѿ���ͨ�������������� 
		ed[j++]=edge[i];
		ans+=edge[i].w;
		fa[ev]=eu;//�������ߵĸ��ϲ� 
		if(j==n-1)break;//����n-1����ʱ����ѭ�� 
	}
 } 
 
 void print()//���ģ�� 
 {
	for(int i=0;i<n-1;i++)
	cout<<"����"<<s[ed[i].u]<<"��"<<s[ed[i].v]<<"������Ϊ"<<ed[i].w<<endl;
  } 
  
void in() //����ģ�� 
{
 	cout<<"������С��������";cin>>n; 
 	cout<<"��������֪·��������";cin>>m;//n��С����m����� 
 	cout<<"�밴˳������С�����ƣ�"<<endl; 
 	for(int i=1;i<=n;i++)
 	{
 		cout<<i<<":";cin>>s[i];
	 }
 	for(int i=1;i<=n;i++) fa[i]=i;
 	cout<<"������ÿ��·���˵������С����·������(����С��1��С��3֮�����Ϊ4��1 3 4)��"<<endl; 
 	for(int i=0;i<m;i++)
 	{
 		int a,b,c;
 		cin>>a>>b>>c;
 	 	if(a<1||a>n||b<1||b>n||c<0)
		{
 			cout<<"���벻�Ϲ淶����������������·����"<<endl; 
 			i--;
 			continue;
		}
 		edge[i].u=a;
 		edge[i].v=b;
 		edge[i].w=c;
	 }	
}
void sset()//��� 
{
	//���ans edge ed fa j
	ans=0;j=0;memset(fa,'\0',sizeof(fa)) ;
	memset(&edge,0,sizeof(struct Edge));
	memset(&ed,0,sizeof(struct Edge));
}
void isconnected()//�ж��Ƿ���ͨ 
{
	if(j<n-1)cout<<"�޷���ͨ����С����"<<endl;
	else{
		cout<<"��ѷ������£�"<<endl;
		print();
		cout<<"ú���ܵ������ܳ���Ϊ"<<ans<<endl; 
	}
 } 
 int main()
 {
 	while(1)
 	{
 		cout<<endl<<"==ú���ܵ��������ϵͳ=="<<endl;
		cout<<"1.��ʼ���"<<"2.�˳�ϵͳ"<<endl; 
		char op;cin>>op;
		if(op=='2')return 1;
		
		in();
		kruskal();
		isconnected();
		sset();
	 }
 }
