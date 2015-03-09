#include<iostream>
#include <iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

class Board {
	public:
		int board[4][4];  //�������� 
		int n;  //�Ѵ������ָ��� 
		Board();  //���캯��
		void randx();  //�����������2/4
		void print();  //��ӡ����
		bool check();  //����Ƿ�GameOver 
		bool up();  //���ϲ��� 
		bool down();  //���²���
		bool left();  //�������
		bool right();  //���Ҳ���
};

Board::Board()  //���캯�� 
{
	memset(board,0,sizeof(board));  //��ʼ��Ϊ0 
	n=0;	
}
void Board::randx()  //�����������2/4 
{
	while(true)
	{
		srand(time(NULL)); 
		int x=rand()%16;  //����������� 
		if(board[x/4][x%4]==0)
		{
			srand(time(NULL)); 
			board[x/4][x%4]=rand()%2==0?2:4;  //�����������2/4 
			n++;
			break;
		}
	}
}
void Board::print() //��ӡ���� 
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		for(k=0;k<33;k++)  //��ӡ���̷�'-' 
			cout<<'-'; 
		cout<<endl;
		for(j=0;j<4;j++)
		{
			if(board[i][j]==0)  //��ӡ���� 
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
bool Board::check()  //����Ƿ�GameOver 
{
	bool flag=true;
	for(int i=0;flag==true,i<4;i++) 
		for(int j=0;flag==true,j<4;j++)
		{
			if(j<3&&board[i][j]==board[i][j+1])  //�Ƿ����������� 
				flag=false;
			if(i<3&&board[i][j]==board[i+1][j])  //�Ƿ����������� 
				flag=false;
		} 
	return flag;
}
bool Board::up()  //���ϲ���
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
	for(j=0;j<4;j++)  //���Ϻϲ� 
	{
		if(board[0][j]&&board[1][j]&&board[0][j]==board[1][j])  //��1��2��� 
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
			if(board[1][j]&&board[2][j]&&board[1][j]==board[2][j])  //�м���� 
			{
				board[1][j]*=2;
				board[2][j]=board[3][j];
				board[3][j]=0;
				flag=true;
				n--;
			}
			else
			{
				if(board[2][j]&&board[3][j]&&board[2][j]==board[3][j])  //��1��2��� 
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
bool Board::down()  //���²���
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
	for(j=0;j<4;j++)  //���ºϲ� 
	{
		if(board[3][j]&&board[2][j]&&board[3][j]==board[2][j])  //��1��2��� 
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
			if(board[2][j]&&board[1][j]&&board[2][j]==board[1][j])  //�м���� 
			{
				board[2][j]*=2;
				board[1][j]=board[0][j];
				board[0][j]=0;
				flag=true;
				n--;
			}
			else
			{
				if(board[1][j]&&board[0][j]&&board[1][j]==board[0][j])  //��1��2��� 
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
	
bool Board::left()  //�������
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
	for(i=0;i<4;i++)  //����ϲ� 
	{
		if(board[i][0]&&board[i][1]&&board[i][0]==board[i][1])  //��1��2��� 
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
			if(board[i][1]&&board[i][2]&&board[i][1]==board[i][2])  //�м���� 
			{
				board[i][1]*=2;
				board[i][2]=board[i][3];
				board[i][3]=0;
				flag=true;
				n--;
			}
			else
			{
				if(board[i][2]&&board[i][3]&&board[i][2]==board[i][3])  //��1��2��� 
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
bool Board::right()  //���Ҳ���
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
	for(i=0;i<4;i++)  //���Һϲ� 
	{
		if(board[i][3]&&board[i][2]&&board[i][3]==board[i][2])  //��1��2��� 
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
			if(board[i][2]&&board[i][1]&&board[i][2]==board[i][1])  //�м���� 
			{
				board[i][2]*=2;
				board[i][1]=board[i][0];
				board[i][0]=0;
				flag=true;
				n--;
			}
			else
			{
				if(board[i][1]&&board[i][0]&&board[i][1]==board[i][0])  //��1��2��� 
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
		b.randx();  //��������������� 
		b.randx();
		b.print(); 
		char ch;
		while(true)
		{
			bool flag=false; //�ж��Ƿ�ı��־ 
			cin>>ch;
			switch(ch)
			{
				case 'w':  //���ϲ���
					flag=b.up();
					break;
				case 's':  //���²���
					flag=b.down();
					break;
				case 'a':  //�������
					flag=b.left();
					break;
				case 'd':  //���Ҳ���
					flag=b.right();
					break;
				default:
					break;		
			}
			if(flag)  //�޸ı�������������� 
			{ 
				b.randx();
			}
			system("cls"); 
			b.print();
			if(b.n==16&&b.check())  //�ж��Ƿ�GameOver 
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
