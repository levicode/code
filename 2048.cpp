#include<iostream>
#include <iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

class Board {
	public:
		int board[4][4];  //棋盘数组 
		int n;  //已存在数字个数 
		Board();  //构造函数
		void randx();  //随机生成数字2/4
		void print();  //打印棋盘
		bool check();  //检查是否GameOver 
		bool up();  //向上操作 
		bool down();  //向下操作
		bool left();  //向左操作
		bool right();  //向右操作
};

Board::Board()  //构造函数 
{
	memset(board,0,sizeof(board));  //初始化为0 
	n=0;	
}
void Board::randx()  //随机生成数字2/4 
{
	while(true)
	{
		srand(time(NULL)); 
		int x=rand()%16;  //产生随机次序 
		if(board[x/4][x%4]==0)
		{
			srand(time(NULL)); 
			board[x/4][x%4]=rand()%2==0?2:4;  //产生随机数字2/4 
			n++;
			break;
		}
	}
}
void Board::print() //打印棋盘 
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		for(k=0;k<33;k++)  //打印棋盘符'-' 
			cout<<'-'; 
		cout<<endl;
		for(j=0;j<4;j++)
		{
			if(board[i][j]==0)  //打印棋子 
				cout<<"| "<<setw(6)<<" ";
			else
				cout<<"| "<<setw(5)<<board[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	for(k=0;k<33;k++)
			cout<<'-'; 
	cout<<endl;
} 
bool Board::check()  //检查是否GameOver 
{
	bool flag=true;
	for(int i=0;flag==true,i<4;i++) 
		for(int j=0;flag==true,j<4;j++)
		{
			if(j<3&&board[i][j]==board[i][j+1])  //是否存在左右相等 
				flag=false;
			if(i<3&&board[i][j]==board[i+1][j])  //是否存在上下相等 
				flag=false;
		} 
	return flag;
}
bool Board::up()  //向上操作
{
	int i,j;
	bool flag=false;
	for(j=0;j<4;j++){
		if(board[0][j]&&board[1][j]&&board[2][j]&&board[3][j])
			continue;
		for(i=1;i<=3;i++)
		{
			if(board[i][j]==0)
				continue;
			int k=0;
			while(k<i&&board[k][j])k++;
			if(k<i)
			{
				board[k][j]=board[i][j];
				board[i][j]=0;
				flag=true;
			}
		}
	}
	for(j=0;j<4;j++)  //向上合并 
	{
		if(board[0][j]&&board[1][j]&&board[0][j]==board[1][j])  //上1上2相等 
		{
			board[0][j]*=2;
			flag=true;
			if(board[2][j]&&board[3][j]&&board[2][j]==board[3][j])
			{
				board[1][j]=board[2][j]*2;
				board[2][j]=board[3][j]=0;
				n-=2;
			}
			else
			{
				board[1][j]=board[2][j];
				board[2][j]=board[3][j];
				board[3][j]=0;
				n--;
			}
		}
		else
		{
			if(board[1][j]&&board[2][j]&&board[1][j]==board[2][j])  //中间相等 
			{
				board[1][j]*=2;
				board[2][j]=board[3][j];
				board[3][j]=0;
				flag=true;
				n--;
			}
			else
			{
				if(board[2][j]&&board[3][j]&&board[2][j]==board[3][j])  //下1下2相等 
				{
					board[2][j]*=2;
					board[3][j]=0;
					flag=true;
					n--;
				}
			}
		}
	}
	return flag;
}
bool Board::down()  //向下操作
{
	int i,j;
	bool flag=false;
	for(j=0;j<4;j++){
		if(board[0][j]&&board[1][j]&&board[2][j]&&board[3][j])
			continue;
		for(i=2;i>=0;i--)
		{
			if(board[i][j]==0)
				continue;
			int k=3;
			while(k>i&&board[k][j])k--;
			if(k>i)
			{
				board[k][j]=board[i][j];
				board[i][j]=0;
				flag=true;
			}
		}
	}
	for(j=0;j<4;j++)  //向下合并 
	{
		if(board[3][j]&&board[2][j]&&board[3][j]==board[2][j])  //下1下2相等 
		{
			board[3][j]*=2;
			flag=true;
			if(board[1][j]&&board[0][j]&&board[1][j]==board[0][j])
			{
				board[2][j]=board[1][j]*2;
				board[1][j]=board[0][j]=0;
				n-=2;
			}
			else
			{
				board[2][j]=board[1][j];
				board[1][j]=board[0][j];
				board[0][j]=0;
				n--;
			}
		}
		else
		{
			if(board[2][j]&&board[1][j]&&board[2][j]==board[1][j])  //中间相等 
			{
				board[2][j]*=2;
				board[1][j]=board[0][j];
				board[0][j]=0;
				flag=true;
				n--;
			}
			else
			{
				if(board[1][j]&&board[0][j]&&board[1][j]==board[0][j])  //上1上2相等 
				{
					board[1][j]*=2;
					board[0][j]=0;
					flag=true;
					n--;
				}
			}
		}
	}
	return flag;
}
	
bool Board::left()  //向左操作
{
	int i,j;
	bool flag=false;
	for(i=0;i<4;i++){
		if(board[i][0]&&board[i][1]&&board[i][2]&&board[i][3])
			continue;
		for(j=1;j<=3;j++)
		{
			if(board[i][j]==0)
				continue;
			int k=0;
			while(k<j&&board[i][k])k++;
			if(k<j)
			{
				board[i][k]=board[i][j];
				board[i][j]=0;
				flag=true;
			}
		}
	}
	for(i=0;i<4;i++)  //向左合并 
	{
		if(board[i][0]&&board[i][1]&&board[i][0]==board[i][1])  //左1左2相等 
		{
			board[i][0]*=2;
			flag=true;
			if(board[i][2]&&board[i][3]&&board[i][2]==board[i][3])
			{
				board[i][1]=board[i][2]*2;
				board[i][2]=board[i][3]=0;
				n-=2;
			}
			else
			{
				board[i][1]=board[i][2];
				board[i][2]=board[i][3];
				board[i][3]=0;
				n--;
			}
		}
		else
		{
			if(board[i][1]&&board[i][2]&&board[i][1]==board[i][2])  //中间相等 
			{
				board[i][1]*=2;
				board[i][2]=board[i][3];
				board[i][3]=0;
				flag=true;
				n--;
			}
			else
			{
				if(board[i][2]&&board[i][3]&&board[i][2]==board[i][3])  //右1右2相等 
				{
					board[i][2]*=2;
					board[i][3]=0;
					flag=true;
					n--;
				}
			}
		}
	}
	return flag;
}
bool Board::right()  //向右操作
{
	int i,j;
	bool flag=false;
	for(i=0;i<4;i++){
		if(board[i][0]&&board[i][1]&&board[i][2]&&board[i][3])
			continue;
		for(j=2;j>=0;j--)
		{
			if(board[i][j]==0)
				continue;
			int k=3;
			while(k>j&&board[i][k])k--;
			if(k>j)
			{
				board[i][k]=board[i][j];
				board[i][j]=0;
				flag=true;
			}
		}
	}
	for(i=0;i<4;i++)  //向右合并 
	{
		if(board[i][3]&&board[i][2]&&board[i][3]==board[i][2])  //右1右2相等 
		{
			board[i][3]*=2;
			flag=true;
			if(board[i][1]&&board[i][0]&&board[i][1]==board[i][0])
			{
				board[i][2]=board[i][1]*2;
				board[i][1]=board[i][0]=0;
				n-=2;
			}
			else
			{
				board[i][2]=board[i][1];
				board[i][1]=board[i][0];
				board[i][0]=0;
				n--;
			}
		}
		else
		{
			if(board[i][2]&&board[i][1]&&board[i][2]==board[i][1])  //中间相等 
			{
				board[i][2]*=2;
				board[i][1]=board[i][0];
				board[i][0]=0;
				flag=true;
				n--;
			}
			else
			{
				if(board[i][1]&&board[i][0]&&board[i][1]==board[i][0])  //左1左2相等 
				{
					board[i][1]*=2;
					board[i][0]=0;
					flag=true;
					n--;
				}
			}
		}
	}
	return flag;
}
int main()
{
	while(true)
	{
		system("cls");  
		cout<<"Welcome To 2048 !"<<endl;
		cout<<"Press w(up)/s(down)/a(left)/d(right)"<<endl;
		Board b;
		b.randx();  //随机产生两个数字 
		b.randx();
		b.print(); 
		char ch;
		while(true)
		{
			bool flag=false; //判断是否改变标志 
			cin>>ch;
			switch(ch)
			{
				case 'w':  //向上操作
					flag=b.up();
					break;
				case 's':  //向下操作
					flag=b.down();
					break;
				case 'a':  //向左操作
					flag=b.left();
					break;
				case 'd':  //向右操作
					flag=b.right();
					break;
				default:
					break;		
			}
			if(flag)  //无改变则不随机产生数字 
			{ 
				b.randx();
			}
			system("cls"); 
			b.print();
			if(b.n==16&&b.check())  //判断是否GameOver 
				break;
		}
		cout<<"Sorry ! Game Over !"<<endl;
		cout<<"Try again ?(y/others)"<<endl;
		cin>>ch;
		if(ch!='y')
		break;
	}
	return 0;
}
