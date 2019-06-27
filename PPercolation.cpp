/*Программа перебирает num случайных расскрасок многоугольника для данного n (n>=3), 
и находит количество расскрасок, при котором из центра до границы 
1) дотекает только цвет 1 (o=1)
2) дотекают цвета 1 и 2 (o=2)
3) дотекают все три цвета 1,2,3 (o=3)*/

#include<iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

int main() 
{
	//ввод n и прочих основных параметров
	short int n, o; int num; 
	cout << "n = "; cin >> n; 
	cout << "Number of random colorings = "; cin >> num;
	cout << "Number of percolated colors = "; cin >> o;
	
	short int k = (n+2)%3; short int G,S; //технические константы 
	if ((n%3)!=2) S=(n+2)/3; else S=(n-2)/3;
	
	short int i,j,r;  //технические константы
	int Sum = 0; //счётчик хороших расскрасок
	short int Center; //координата 'x' центра
	
	//задаем центр в зависимости от n%3
	if (n%3==0) Center=(2*n)/3 + 2;
	else if (n%3==1) Center=(4*n+2)/6 + 2;
	else Center=(4*n-2)/6 + 2;
	
	//Задание многоугольника как двумерный массив
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
	
	//задание краёв многоугольника (разные случаи в зависимости от n%3)
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
	
	//задание многоугольника. 1 -клетка многоугольника; 9 - технические мнимые клетки; 0 -внешность многоуольника.
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
	//задание нижней части
	for (i = n+3; i<= (2*n + 1); i++)
	{
		for (j = 1; j<=((4*n)/3 + 1); j++)
		{
			polygon[i][j] = polygon[2*n+4 - i][j];
		}
	}
	}
	else //когда n%3==1
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
	//задание нижней части
	for (i = n + 3; i<= (2*n + 1); i++)
	{
		for (j = 1; j<=((4*n)/3 + 1); j++)
		{
			polygon[i][j] = polygon[2*n+4 - i][j];
		}
	}
	}
	
	//рисование многоугольника
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
	
	per: if (ii==num) goto end;//Перебор завершён
	
	ii++;
	
	//Случайная раскраска 		
	//p соответветствует цвету p-1
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
	
	polygon[n+2][Center]=1; //цвет центра всегда 0
	
	G=1;
	for (k=2;k<=o+1;k++)
	//перебор цветов
	{
	nnn:{
			short int h = n+2; //высота центра
			short int v = Center; //координата 'x' центра
			while (1)
			{
			prod:if ((polygon[h+2][v] ==1) || (polygon[h+2][v] ==k)) //если можно идти вниз, идём
					h += 2;
				else
				{
					//начинаем бродить по границе
					short int t=0; //Определитель многоугольников 
					bool q = 0; //Включается, когда начинаем обход границы
					short int h_start = h; //запоминаем высоту клетки, на которой упёрлись в границу
					short int h_max=h; //переменная для сохранения максимальной высоты по мере обхода границы
					short int v_start = v; //запоминаем 'x' координату клетки, на которой упёрлись в границу
					//Запоминаем клетку, в которой мы упёрлись в границу
					short int r=0; //где граница
					short int g=1; //куда идём	
					/*0-юг; 1-юго-запад; 2-северо-запад; 3-север; 4-северо-восток; 5-юго-восток.
					r показывает, где в данный момент находится граница, 
					g показывает, куда мы будем пытаться пройти. 
					Если мы не можем пройти в какую-нибудь клетку, то изменяем значение 
					r (ставим границу) и изменяем значение g (пытаемя пойти в другую сторону)
					Если мы можем пойти в какую-ниюудь клетку, то меняем значение r так, чтобы
					она показывала на уже известную границу со стороны новой клетки. В соответствии
					с r выбираем новое направление g.
					
					Тут мы начинаем рисовать границу*/
					while(1)
					{	
					/*Выходит из цикла, либо если граница замкнулась, либо если 
					мы достигли границы многоугольника*/					
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
								//Ищем самую низкую точку границы
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
							//не обошли ли мы границу
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
									//продолжаем путь вниз
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
									//Ищем самую низкую точку границы
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
									//Ищем самую низкую точку границы
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
				//Проверяем, не у границы ли мы
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
       
	//вывод ответа 
	end:cout<<endl<<"Number of random colorings, in which ";
	if (o==1) cout<<"fluid "; else cout<<"fluids ";
	for (i=1;i<=o;i++) 
	{cout<<i; if (i!=o) cout<< ", "; else cout << " ";}
	if (o==1) cout<<"is "; else cout<<"are ";
	cout<<"percolated = "<<Sum;
	return 0;
}
