/*��������� ���������� num ��������� ���������� �������������� ��� ������� n (n>=3), 
� ������� ���������� ����������, ��� ������� �� ������ �� ������� 
1) �������� ������ ���� 1 (o=1)
2) �������� ����� 1 � 2 (o=2)
3) �������� ��� ��� ����� 1,2,3 (o=3)*/

#include<iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

int main() 
{
	//���� n � ������ �������� ����������
	short int n, o; int num; 
	cout << "n = "; cin >> n; 
	cout << "Number of random colorings = "; cin >> num;
	cout << "Number of percolated colors = "; cin >> o;
	
	short int k = (n+2)%3; short int G,S; //����������� ��������� 
	if ((n%3)!=2) S=(n+2)/3; else S=(n-2)/3;
	
	short int i,j,r;  //����������� ���������
	int Sum = 0; //������� ������� ����������
	short int Center; //���������� 'x' ������
	
	//������ ����� � ����������� �� n%3
	if (n%3==0) Center=(2*n)/3 + 2;
	else if (n%3==1) Center=(4*n+2)/6 + 2;
	else Center=(4*n-2)/6 + 2;
	
	//������� �������������� ��� ��������� ������
	short int **polygon; polygon = new short int *[2*n + 3];
	for(i = 1; i<=(2*n + 3); i++)
		polygon[i] = new short int[(4*n+2)/3 + 3];
	
	for (i = 1; i<=(2*n + 3); i++)
	{
		for (j = 1; j<=((4*n+2)/3 + 3); j++)
		{
			polygon[i][j] = 0;
		}
	}
	
	//������� ���� �������������� (������ ������ � ����������� �� n%3)
	if ((n%3)==0)
	{
		if ((n % 6) == 0)
		{
			for (i = 1; i <= (n/3); i= i+2)
			{
				polygon[3][(2*n)/3 + 2 - i] = 1;
				polygon[3][(2*n)/3 + 2 + i] = 1;
			}
		}
		else
		{
			polygon[3][(2*n)/3 + 2] = 1;
			for (i = 2; i <= ((n/3)-1); i= i+2)
			{
				polygon[3][(2*n)/3 + 2 - i] = 1;
				polygon[3][(2*n)/3 + 2 + i] = 1;
			}
		}
	}
	else if ((n%3)==1)
	{
		if (((n-1) % 6) == 0)
		{
			polygon[3][(2*n + 1)/3 + 2] = 1;
			for (i = 2; i <= ((n + 2)/3); i= i + 2)
			{
				polygon[3][(2*n+1)/3 + 2 - i] = 1;
				polygon[3][(2*n+1)/3 + 2 + i] = 1;
			}
		} 
		else
		{
			for (i = 1; i <= ((n + 2)/3); i= i+2)
			{
				polygon[3][(2*n + 1)/3 + 2 - i] = 1;
				polygon[3][(2*n + 1)/3 + 2 + i] = 1;
			}
		}
	}
	else
	{
		if (((n - 2) % 6) == 0)
		{
			for (i = 1; i <= ((n - 2)/3); i= i + 2)
			{
				polygon[3][(2*n+2)/3 + 1 - i] = 1;
				polygon[3][(2*n+2)/3 + 1 + i] = 1;
			}
		}
		else
		{
			polygon[3][(4*n-2)/6 + 2] = 1;
			for (i = 2; i <= (((n-2)/3)-1); i= i+2)
			{
				polygon[3][(4*n-2)/6 + 2 - i] = 1;
				polygon[3][(4*n-2)/6 + 2 + i] = 1;
			}
		}
	}
	
	//������� ��������������. 1 -������ ��������������; 9 - ����������� ������ ������; 0 -��������� �������������.
	if((n%3)!=1)
	{
	for (i = 4; i<= (n + 2); i++)
	{
		for (j = 1; j<=((4*n)/3 + 1); j++)
		{
			if ((k == 1) || (k == 2)) 
			{
				if (polygon[i-1][j+1]==1)
				{
					S = S + 1; k = ((k + 1)%3);
					for (r = 0; r <= (S-2); r++)
					{
						polygon[i][j + 2*r] = 1;
						polygon[i][j + 1 + 2*r] = 9;
					}
					polygon[i][j + 2*r] = 1;
					j = ((4*n)/3 + 2);
				}
			}
			if (k == 0)
			{
				if (polygon[i-1][j-1]==1)
				{
					S = S - 1; k = ((k + 1)%3);
					for (r = 0; r <= (S-2); r++)
					{
						polygon[i][j + 2*r] = 1;
						polygon[i][j + 1 + 2*r] = 9;
						}
					polygon[i][j + 2*r] = 1;
					j = ((4*n)/3 + 2);
				}
			}
		}
	}
	//������� ������ �����
	for (i = n+3; i<= (2*n + 1); i++)
	{
		for (j = 1; j<=((4*n)/3 + 1); j++)
		{
			polygon[i][j] = polygon[2*n+4 - i][j];
		}
	}
	}
	else //����� n%3==1
	{
	for (i = 4; i<= (n + 3); i++)
	{
		for (j = 1; j<=((4*n-1)/3 + 2); j++)
		{
			if ((k == 1) || (k == 2)) 
			{
				if (polygon[i-1][j+1]==1)
				{
					S = S + 1; k = ((k + 1)%3);
					for (r = 0; r <= (S-2); r++)
					{
						polygon[i][j + 2*r] = 1;
						polygon[i][j + 1 + 2*r] = 9;
					}
					polygon[i][j + 2*r] = 1;
					j = (4*n-1)/3 + 3;
				}
			}
			if (k == 0)
			{
				if (polygon[i-1][j-1]==1)
				{
					S = S - 1; k = ((k + 1)%3);
					for (r = 0; r <= (S-2); r++)
					{
						polygon[i][j + 2*r] = 1;
						polygon[i][j + 1 + 2*r] = 9;
						}
					polygon[i][j + 2*r] = 1;
					j = (4*n-1)/3 + 3;
				}
			}
		}
	}
	//������� ������ �����
	for (i = n + 3; i<= (2*n + 1); i++)
	{
		for (j = 1; j<=((4*n)/3 + 1); j++)
		{
			polygon[i][j] = polygon[2*n+4 - i][j];
		}
	}
	}
	
	//��������� ��������������
/*	for (i = 1; i<=(2*n + 3); i++)
	{
		for (j = 1; j<=((4*n)/3 + 3); j++)
		{
			cout << polygon[i][j];
		}
		cout << endl;
	}*/
	
	int ii=0;
	srand(time(0));
	k=2;
	
	per: if (ii==num) goto end;//������� ��������
	
	ii++;
	
	//��������� ��������� 		
	//p ���������������� ����� p-1
	for (i=3; i<=(2*n+1); i++)
	{
		for (j = 3; j<=((4*n)/3 + 1); j++)
		{
			if ((polygon[i][j] == 1) || polygon[i][j] == 2 || polygon[i][j] == 3 || polygon[i][j] == 4)
			{
				polygon[i][j]=rand()%4+1;
			}
		}
	}
	
	polygon[n+2][Center]=1; //���� ������ ������ 0
	
	G=1;
	for (k=2;k<=o+1;k++)
	//������� ������
	{
	nnn:{
			short int h = n+2; //������ ������
			short int v = Center; //���������� 'x' ������
			while (1)
			{
			prod:if ((polygon[h+2][v] ==1) || (polygon[h+2][v] ==k)) //���� ����� ���� ����, ���
					h += 2;
				else
				{
					//�������� ������� �� �������
					short int t=0; //������������ ��������������� 
					bool q = 0; //����������, ����� �������� ����� �������
					short int h_start = h; //���������� ������ ������, �� ������� ������� � �������
					short int h_max=h; //���������� ��� ���������� ������������ ������ �� ���� ������ �������
					short int v_start = v; //���������� 'x' ���������� ������, �� ������� ������� � �������
					//���������� ������, � ������� �� ������� � �������
					short int r=0; //��� �������
					short int g=1; //���� ���	
					/*0-��; 1-���-�����; 2-������-�����; 3-�����; 4-������-������; 5-���-������.
					r ����������, ��� � ������ ������ ��������� �������, 
					g ����������, ���� �� ����� �������� ������. 
					���� �� �� ����� ������ � �����-������ ������, �� �������� �������� 
					r (������ �������) � �������� �������� g (������� ����� � ������ �������)
					���� �� ����� ����� � �����-������ ������, �� ������ �������� r ���, �����
					��� ���������� �� ��� ��������� ������� �� ������� ����� ������. � ������������
					� r �������� ����� ����������� g.
					
					��� �� �������� �������� �������*/
					while(1)
					{	
					/*������� �� �����, ���� ���� ������� ����������, ���� ���� 
					�� �������� ������� ��������������*/					
						if (g==0)
						{
							if ((polygon[h+2][v] == 1) || (polygon[h+2][v] == k))
							{
								h+=2;
									
								if (r==5)
								{
									r=4;
									g=5;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else 
												goto per;
										}
									}
								}
								else if (r==1)
								{
									r=2;
									g=1;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else goto per;
										}
									}
								}	
							}
							else
							{
								//���� ����� ������ ����� �������
							if ((v_start == v)&&(h>=(n + 2)))
							{
								t++;
								if (h > h_max)
									h_max=h;
							}
							g++;
							r=0;
							}
						}
						else if (g==1)
						{
							//�� ������ �� �� �������
							if ((h == h_start) && (v == v_start) && (q))
							{
 								if ((t%2)==1)
								{
									if (k==o+1)
										goto per;
									else
									{
										k++;
										goto nnn;
									}
								}
								else if ((t%2)==0)
								{
									//cout<<1<<" "<< h_max<<endl;
									//���������� ���� ����
									q=0;
									t=0;
									h = h_max;
									goto prod;
								}
							}
							if ((polygon[h+1][v-1] == 1) || (polygon[h+1][v-1] ==k))
							{
								h++;
								v--;
			
								if (r==0)
								{
									r=5;
									g=0;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else 
												goto per;
										}
									}
									q=1;
								}
								else if (r==2)
								{
									if ((v_start == v)&&(h>(n + 2)))
									{
										t++;
										if (h > h_max)
											h_max=h;
									}
									r=3;
									g=2;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else goto per;
										}
									}
									q=1;
								}
							}
							else
							{
								g++;
								r=1;
								q=1;
							}
						}
						else if (g==2)
						{
							if ((polygon[h-1][v-1] ==1) || (polygon[h-1][v-1] ==k))
							{
								h--;
								v--;
				
								if (r==1)
								{
									//���� ����� ������ ����� �������
									if ((v_start == v)&&(h>=(n + 2)))
									{
										t++;
										if (h > h_max)
											h_max=h;
									}											
									r=0;
									g=1;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else goto per;
										}
									}
								}
								else if (r==3)
								{
									r=4;
									g=3;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else goto per;
										}
									}
								}
							}
							else
							{
								g++;
								r=2;
							}
						}
						else if (g==3)
						{					
								if ((polygon[h-2][v] ==1) || (polygon[h-2][v] ==k))
								{
									h-=2;
								
										if (r==2)
										{
											r=1;
											g=2;
											if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
											(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
											{
												if (G==o)
												{
													Sum++;
													goto per;
												}
												else 
												{
													if (k<o+1)
													{
														G++;
														k++;
														goto nnn;
													}
													else goto per;
												}
											}
										}
										else if (r==4)
										{
											r=5;
											g=4;
											if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
											(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
											{
												if (G==o)
												{
													Sum++;
													goto per;
												}
												else 
												{
													if (k<o+1)
													{
														G++;
														k++;
														goto nnn;
													}
													else goto per;
												}		
											}
										}
								}
								else
								{
									if ((v_start == v)&&(h>(n+2)))
									{
										t++;
										if (h > h_max)
											h_max=h;
									}
									
									g++;
									r=3;
								}
							}
						else if (g==4)
						{
							if ((polygon[h-1][v+1] ==1) || (polygon[h-1][v+1] ==k))
							{
								h--;
								v++;					
							
								if (r==3)
								{
									r=2;
									g=3;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else goto per;
										}
									}
								}
								else if (r==5)
								{
									//���� ����� ������ ����� �������
								if ((v_start == v)&&(h>=(n + 2)))
									{
										t++;
										if (h > h_max)
											h_max=h;
									}			
									r=0;
									g=5;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else goto per;
										}
									}
								}
							}
							else
							{
								g++;
								r=4;
							}
						}
						else if (g==5)
						{
							if ((polygon[h+1][v+1] == 1) || (polygon[h+1][v+1] ==k))
							{
								h++;
								v++;
													
								if (r==4)
								{
									if ((v_start == v)&&(h>(n + 2)))
									{
										t++;
										if (h > h_max)
											h_max=h;
									}							
									r=3;
									g=4;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else goto per;
										}
									}
								}
								else if (r==0)
								{
									r=1;
									g=0;
									if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
									(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
									{
										if (G==o)
										{
											Sum++;
											goto per;
										}
										else 
										{
											if (k<o+1)
											{
												G++;
												k++;
												goto nnn;
											}
											else goto per;
										}
									}
								}
							}
							else
							{
								g=0;
								r=5;
							}
						}
					}
				}
				//���������, �� � ������� �� ��
				if ((polygon[h+2][v] == 0) || (polygon[h-2][v]==0) || (polygon[h+1][v-1]==0) ||
				(polygon[h+1][v+1]==0) || (polygon[h-1][v-1]==0) || (polygon[h-1][v+1]==0))
				{
					if (G==o)
					{
						Sum++;
						goto per;
					}
					else 
					{
						if (k<o+1)
						{
							G++;
							k++;
							goto nnn;
						}
						else goto per;
					}
				}
			}
		}
		if (k==o+1)
			goto per;
	}
       
	//����� ������ 
	end:cout<<endl<<"Number of random colorings, in which ";
	if (o==1) cout<<"fluid "; else cout<<"fluids ";
	for (i=1;i<=o;i++) 
	{cout<<i; if (i!=o) cout<< ", "; else cout << " ";}
	if (o==1) cout<<"is "; else cout<<"are ";
	cout<<"percolated = "<<Sum;
	return 0;
}
