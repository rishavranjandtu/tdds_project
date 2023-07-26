#include<graphics.h>
#include<iostream>
#include<vector>
#include<conio.h>
#include<map>
#include <iomanip>
#include<vector>
using namespace std;

class tdds
{
	public:
	vector<char>inp;
	vector<char>out;
	vector<string>gate;
	vector<string>gate_name;
	map<string,vector<char> >m1;
	map<string,vector<char> >m2;
	map<char,vector<int> >ans;
	vector<char>p_out;
	map<char,vector<int> >i_ans;
	char dif;
	
	void start()
	{
		system("cls");
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
	
	  cout<<endl;
	  cout<<endl;
	  int in;
	  cout<<" \t\t \t       Enter number of Inputs:";
	  cin>>in;
	  inp.resize(in);
	  cout<<endl;
	  cout<<endl;
	  cout<<" \t\t \t       Enter name of the Inputs:"<<endl;
	  cout<<" \t\t \t               ";
	  for(int i=0;i<in;i++) 
	  {
		char c;
		cin>>c;
		inp[i]=c;
	  if(i!=in-1)cout<<" \t\t \t               ";
	  }
	  cout<<endl;
	  system("cls");
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
	  int g;
   	  cout<<" \t\t \t       Enter number of gates:";
	  cin>>g;
	  cout<<endl;
	  gate.resize(g);
	  gate_name.resize(g);
	  
	  cout<<" \t\t \t       Type the name and type of the gate:"<<endl;
	  cout<<" \t\t \t                   ";
	  
	  for(int i=0;i<g;i++)
	  {
	  	string name;
		string type;
		 cin>>name;
		cin>>type;
	 	gate[i]=type;
	 	gate_name[i]=name;
	 	if(i!=g-1)cout<<" \t\t \t                   ";
	  }
	  cout<<endl;
	  system("cls");
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
	  int o;
	  cout<<" \t\t \t       Enter the number of output lines:";
	  cin>>o;
	  out.resize(o);
	  cout<<endl;
	  cout<<" \t\t \t       Enter name of output lines"<<endl;
	  cout<<" \t\t \t                ";
	  for(int i=0;i<o;i++) 
	  {
		char c;
		cin>>c;
		out[i]=c;
		cout<<" \t\t \t                ";
	  }
	  cout<<endl;
	  system("cls");
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
	  cout<<" \t\t \t       Enter the inputs of each gates"<<endl;
	  cout<<" \t\t \t             ";
	  for(int i=0;i<gate_name.size();i++)
	  {
	  	char a;
	  	char b;
	  	cout<<gate_name[i]<<":-";
	  	cin>>a>>b;
	  	m1[gate_name[i]].push_back(a);
	  	m1[gate_name[i]].push_back(b);
	  	cout<<" \t\t \t             ";
      }
      cout<<endl;
	  cout<<" \t\t \t       Enter the outputs of each gates"<<endl;
	  cout<<" \t\t \t             ";
	  for(int i=0;i<gate_name.size();i++)
	  {
	  	char a;
	  	cout<<gate_name[i]<<":-";
	  	cin>>a;
	  	m2[gate_name[i]].push_back(a);
	  	cout<<" \t\t \t             ";
	  }
	  cout<<endl;
	  system("cls");
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
	  int p_o;
	  cout<<" \t\t \t       Enter the no of primary outputs:";
	  cin>>p_o;
	  cout<<endl;
	  p_out.resize(p_o);
	  cout<<" \t\t \t       Enter the primary outputs:"<<endl;
	  cout<<" \t\t \t              ";
	  for(int i=0;i<p_o;i++)
	  {
	  	char a;
	  	cin>>a;
	  	p_out[i]=a;
	  	if(i!=p_o)cout<<" \t\t \t              ";
	  }
	  cout<<endl;
	  value_add();
	}
	 
	void value_add()
	{

		for(int i=0;i<inp.size();i++)
		{
			ans[inp[i]].push_back(1);
			ans[inp[i]].push_back(1);
		}
		i_ans=ans;
	}
	vector<int>ad(vector<char>v)
	{
		auto xx=ans[v[0]];
		auto yy=ans[v[1]];
		int a=xx[0];
		int b=xx[1];
		int c=yy[0];
		int d=yy[1];
		int ans_a=min(a,c)+1;
		int ans_b=b+d+1;
		vector<int>vv;
		vv.push_back(ans_a);
		vv.push_back(ans_b);
		return vv;
	}
	vector<int>orr(vector<char>v)
	{
		auto xx=ans[v[0]];
		auto yy=ans[v[1]];
		int a=xx[0];
		int b=xx[1];
		int c=yy[0];
		int d=yy[1];
		int ans_b=min(b,d)+1;
		int ans_a=a+c+1;
		vector<int>vv;
		vv.push_back(ans_a);
		vv.push_back(ans_b);
		return vv;
	}
	vector<int>naand(vector<char>v)
	{
		auto xx=ans[v[0]];
		auto yy=ans[v[1]];
		int a=xx[0];
		int b=xx[1];
		int c=yy[0];
		int d=yy[1];
		int ans_a=b+d+1;
		int ans_b=min(a,c)+1;
		vector<int>vv;
		vv.push_back(ans_a);
		vv.push_back(ans_b);
		return vv;
	}
	vector<int>noor(vector<char>v)
	{
		auto xx=ans[v[0]];
		auto yy=ans[v[1]];
		int a=xx[0];
		int b=xx[1];
		int c=yy[0];
		int d=yy[1];
		int ans_a=min(b,d)+1;
		int ans_b=a+c+1;
		vector<int>vv;
		vv.push_back(ans_a);
		vv.push_back(ans_b);
		return vv;
	}
	vector<int>xoor(vector<char>v)
	{
		auto xx=ans[v[0]];
		auto yy=ans[v[1]];
		int a=xx[0];
		int b=xx[1];
		int c=yy[0];
		int d=yy[1];
		int ans_a=min(a+c,b+d)+1;
		int ans_b=min(a+d,b+c)+1;
		vector<int>vv;
		vv.push_back(ans_a);
		vv.push_back(ans_b);
		return vv;
	}
	vector<int>xnoor(vector<char>v)
	{
		auto xx=ans[v[0]];
		auto yy=ans[v[1]];
		int a=xx[0];
		int b=xx[1];
		int c=yy[0];
		int d=yy[1];
		int ans_b=min(a+c,b+d)+1;
		int ans_a=min(a+d,b+c)+1;
		vector<int>vv;
		vv.push_back(ans_a);
		vv.push_back(ans_b);
		return vv;
	}
	void cal()
	{
		system("cls");
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
		map<char,vector<int> >anns=i_ans;
		
		for(int i=0;i<gate.size();i++)
		{
			if(gate[i]=="AND")
			{
				vector<int>x=ad(m1[gate_name[i]]);
				vector<char>y=m2[gate_name[i]];
					anns[y[0]].push_back(x[0]);
					anns[y[0]].push_back(x[1]);	
			}
			else if(gate[i]=="OR")
			{
			vector<int>x=orr(m1[gate_name[i]]);
				vector<char>y=m2[gate_name[i]];
					anns[y[0]].push_back(x[0]);
					anns[y[0]].push_back(x[1]);
			}
			else if(gate[i]=="NAND")
			{
			vector<int>x=naand(m1[gate_name[i]]);
				vector<char>y=m2[gate_name[i]];
					anns[y[0]].push_back(x[0]);
					anns[y[0]].push_back(x[1]);
			}
			else if(gate[i]=="NOR")
			{
			vector<int>x=noor(m1[gate_name[i]]);
				vector<char>y=m2[gate_name[i]];
					anns[y[0]].push_back(x[0]);
					anns[y[0]].push_back(x[1]);
			}
			else if(gate[i]=="XOR")
			{
			vector<int>x=xoor(m1[gate_name[i]]);
				vector<char>y=m2[gate_name[i]];
					anns[y[0]].push_back(x[0]);
					anns[y[0]].push_back(x[1]);
			}
			else if(gate[i]=="XNOR")
			{
			vector<int>x=xnoor(m1[gate_name[i]]);
				vector<char>y=m2[gate_name[i]];
					anns[y[0]].push_back(x[0]);
					anns[y[0]].push_back(x[1]);
			}
				ans=anns;
		}
		ans=anns;
		char f;
		int summ=0;
		for(int i=0;i<p_out.size();i++)
		{
			auto x=ans[p_out[i]];
			int g=(x[0]+x[1])/2;
			if(g>summ)
			{
				summ=g;
				f=p_out[i];
			}
		}
		dif=f;
		cout<<endl;
		cout<<" \t\t \t                Loading"<<endl;
		char v=219;
		cout<<"\t";
		for(int i=0;i<70;i++)
		{
			cout<<v;
			Sleep(30);
		}
	}
	
	void disp()
	{
		system("cls");
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
		int op;
		cout<<endl;
		do
		{
		cout<<" \t\t \t       The CCO AND CC1 of each points are    "<<endl;
		cout<<"\t\t========================================================"<<endl;
		cout<<"\t              CC0        ||        CC1          "<<endl;
		cout<<"\t\t========================================================"<<endl;
		for( auto x:ans)
		{
			auto y=x.second;
		cout<<"\t  "<<x.first<<"\t       "<<y[0]<<"                  "<<y[1]<<"      "<<endl;
		}
		cout<<endl;
		cout<<"\t  The most difficult ciruit to be set is:  "<<dif<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"Enter 0 for back"<<endl;
		cin>>op;
	    }while(op!=0);
		
	}
	void cg()
	{
		system("cls");
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
		cout<<" \t\t \t         Select the new type of gates:"<<endl;
		cout<<endl;
	  for(int i=0;i<gate.size();i++)
	  {
	  	string s;
	  	cout<<" \t\t \t         New type of "<<gate_name[i]<<": ";
	  	cin>>s;
	  	gate[i]=s;
	  }
	  cal();
	}
};
int main()
{
	tdds t;
	int c;
	do
	{
		system("cls");
		cout<<endl;
		//cout<<"*****************************************************************************************"<<endl;
	    cout<<"*****************************************************************************************"<<endl;
	    cout<<" \t\t \t                TDDS PROJECT"              <<endl;
	    cout<<"*****************************************************************************************"<<endl;
		//cout<<"*****************************************************************************************"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<" \t\t \t             1. Create a circuit      "<<endl;
		cout<<" \t\t \t             2. Calculate CC0 AND CC1 "<<endl;
		cout<<" \t\t \t             3. Calculate CO          "<<endl;
		cout<<" \t\t \t             4. Display the result    "<<endl;
		cout<<" \t\t \t             5. Change the gate       "<<endl;
		cout<<" \t\t \t             6. Exit                  "<<endl;
		cout<<endl;
		cout<<" \t\t \t             Enter any option: ";
		cin>>c;
		system("cls");
		if(c==1) 
		{
		t.start();
	    }
	    else if(c==2) t.cal();
	    else if(c==4) t.disp();
		else if(c==5) t.cg();
		else if(c==6)break;
		
	}while(c!=6);
	return 0;
}


