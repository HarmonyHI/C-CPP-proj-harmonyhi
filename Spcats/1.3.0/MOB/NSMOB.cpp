#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int fun(int x)
{
	if (x > 1)
		return x + fun(x - 1);
	else
		return x;
}

int main()
{
	int q, menucir, menuerr, debug;
	int schoolcir, schsync, location, file;
	int school[100];
	int xxx=0, beginning=0;
	debug = 0;
	menucir = 2;
	while (beginning <= 100)
	{
			school[xxx] = 0;
			xxx = xxx + 1;
			beginning = beginning + 1;
	}
	while (menucir == 2)
	{
		menuerr = 1;
		while (menuerr == 1)
		{
			system("cls");
			if(debug==1)
			{
			printf("DEBUGMODE ON\n");
			 } 
			printf("     1 to Beep program\n");
			printf("     2 to Pow calculator\n");
			printf("     3 to Week calculator\n");
			printf("     4 to Egg\n");
			printf("     5 to Seat calculator\n");
			printf("     6 to Android tool box\n");
			printf("     7 to Cir cal\n");
			printf("     8 to Data saver\n");
			printf("     9 to Timer\n\n\n");
			printf("PRESS KEY TO CHOOSE FOUCTIONS\n");
			scanf("%d", &q);
			if ((q == 1) || (q == 2) || (q == 3) || (q == 4) || (q == 5) || (q == 6) || (q == 7)
				|| (q == 8) || (q == 9))
			{
				menuerr = 0;
			}
			if ((q != 5) && (q != 4) && (q != 8) && (q != 6) && (q != 3) && (q != 2) && (q != 9)
				&& (q != 1) && (q != 7)&& (q != 5407))
			{
				printf("input error and try again\n");
				system("pause");
				system("cls");
			}
			if (q==5407)
			{
			if(debug==1)
			{debug=0;}
			else
			{debug=1;}
			 } 
		}
		while ((q == 1) || (q == 2) || (q == 6) || (q == 3) || (q == 4) || (q == 7) || (q == 9)
			   || (q == 8) || (q == 5))
		{
			if (q == 9)
			{
				int goaltime;
				int timeold;
				int timecir=1;
				int timemenucir=0;
				int timemach = 0;
				int timenow = 0;
				int alarmdata;
				int alarmcho;
				int ambcho = 0;
				int lasttime;
				int alarm=0;
				int maker=0;
				int b;
				int checker=0;
				int beepcho=1;
				int year, month, day, hour, minute, second;
				while(timemenucir==0)
				{
				system("cls");
				printf("Press 1 to alarm,2 to timer only ,others to back main menu\n");
				printf("Warnning:TIMER could NOT back to any menu\n");
				scanf("%d", &ambcho);
				if ((ambcho != 1) || (ambcho != 2))
				{
					q = 999;
					timemenucir=1;
					system("cls");
				}
				printf("LOADING......\n");
                system("cls");
		if (ambcho == 1)
					{
					printf("Input goal time (second)\n");
					scanf("%d", &goaltime);
					printf("Beep when times up？(0 to choose)\n");
					scanf("%d", &beepcho);
					printf("LOADING\n");
					goaltime = goaltime + 1;
					time_t t;
					struct tm *lt;
					time(&t);
					lt = localtime(&t);	
					b = lt->tm_hour;
					b = b + 8;
					if (b > 24)
					{
						b = b - 24;
					}
					{
						day = lt->tm_mday;
						year = lt->tm_year + 1900;
						month = lt->tm_mon + 1;
						hour = b;
						minute = lt->tm_min;
						second = lt->tm_sec;
					}
					timeold = 60 * 60 * 24 * day + 60 * 60 * hour + 60 * minute + second;
				}
				if ((ambcho == 1) || (ambcho == 2))
				{

				while (timecir == 1)
				{

					checker = 0;
					maker = 0;
					while (timecir == 1)
					{
						time_t t;
						struct tm *lt;
						time(&t);
						lt = localtime(&t);	
						b = lt->tm_hour;
						b = b + 8;
						if (b > 24)
						{
							b = b - 24;
						}
						{
							day = lt->tm_mday;
							year = lt->tm_year + 1900;
							month = lt->tm_mon + 1;
							hour = b;
							minute = lt->tm_min;
							second = lt->tm_sec;
						}
						maker = second - checker;
											timenow = 60 * 60 * 24 * day + 60 * 60 * hour + 60 * minute + second;
						
												if (timenow - timeold == goaltime)
						{
							system("cls");
							printf("TIMES UP\n");
							if(beepcho==0)
							{
								if((debug==1)&&(school[23]!=0)&&(school[24]!=0))
								{
							
						    }
							    else
							    {
							
							}
						}
							system("pause");
							printf("Continue timer(any) or exit alarm(0) ?\n");
							printf("Warnning:TIMER could NOT back to any menu\n");
							ambcho=2;
							if(debug==1) 
							{
								printf("DEBUG LOG\n");
								printf("goaltime:%d\n",goaltime);
								printf("timeold:%d\n",timeold);
								printf("timecir:%d\n",timecir);
								printf("timemenucir:%d\n",timemenucir);
								printf("alarmdata:%d\n",alarmdata);
								printf("ambcho:%d\n",ambcho);
								printf("timemach:%d\n",timemach);
								printf("timenow:%d\n",timenow);
								printf("maker:%d\n",maker);
								printf("alarm:%d\n",alarm);
								printf("b:%d\n",b);
								printf("checker:%d\n",checker);
								printf("year:%d\n",year);
								printf("month:%d\n",month);
								printf("day:%d\n",day);
								printf("hour:%d\n",hour);
								printf("minute:%d\n",minute);
								printf("second:%d\n",second);
								printf("alarmcho:%d\n",alarmcho);
								printf("q:%d\n",q);	
							}
							scanf("%d", &alarmcho);
							if (alarmcho == 0)
							{
                                ambcho=999;
								timecir=999;
								system("cls");
							}
						}
						
						if (maker == 1)
						{
							if (minute <= 9)
							{
								system("cls");
								printf("%d/%d/%d %d:0%d:", year, month, day, hour, minute);
							}
							else
							{
								system("cls");
								printf("%d/%d/%d %d:%d:", year, month, day, hour, minute);
							}
							if (second <= 9)
							{
								printf("0%d\n", second);
							}
							else
							{
								printf("%d\n", second);
							}
							if (1 == 1)
							{
								timemach = second;
								timemach = 9475 * log(timemach);
								while (timemach > 100)
								{
									timemach = timemach - 100;
								}
								timemach = timemach * 8 + timemach;
								printf("BY TIME LOGGER:%d\n", timemach);
							}
							if (ambcho==1)
							{
								lasttime=goaltime-(timenow-timeold);
								printf("REMAIN TIME:%d\n",lasttime);
							}
						}
						checker = second;
					}
				}
				}
			}
			}
			if (q == 8)
			{
				system("cls");
				printf("Data saver MAX100\n");
				if(debug==1)
				{
					printf("THE 24th SAVER CONTROLED BEEPER W\n");
					printf("THE 25th SAVER CONTROLED BEEPER T\n");
				}
				beginning = 0;
				xxx = 0;
				int inputcir = 0;	// 初始化输入循环变量
				int tableler=0; 
				int locationerr=0;
				while (inputcir != 1)
				{
					while(locationerr==0)
					{
					printf("Input location\n");
					scanf("%d", &location);
					if((location>=1)&&(location<=100))
					{locationerr=1;}
					else
					{
					printf("OUT OF SPACE!\n");
					system("pause");
					system("cls");
					printf("Data saver MAX100\n");
					}
					} 
					location = location - 1;
					printf("Input file\n");
					scanf("%d", &file);
					school[location] = file;	// 分配存储量
					printf("SAVED!\n");
					printf("Input 1 to end input?\n");
					scanf("%d", &inputcir);
					system("cls");
					printf("Data saver MAX100\n");
					if(inputcir!=1) 
					{locationerr=0;}
				}
				schoolcir = 0;
				printf("DATA FOLLOWING THESE\n");
				while (schoolcir < 100)
				{
					schsync = school[schoolcir];
					schoolcir = schoolcir + 1;
					printf("%d ", schsync);
					tableler=schoolcir%10;
					if(tableler==0)
					{
					printf("\n");
					}
				}

				system("pause");
				q = 888;
				system("cls");
			}
			if (q == 2)
			{
				system("cls");
				while (q == 2)
				{
					int y, w, h, c, e, r;
					printf("a^b calculator BY NS\n");
					printf("OR 999^999 to file READING CAL\n");
					c = 1;
					w = 0;
					scanf("%d%d", &y, &h);
					if ((y == 999) && (h == 999))
					{
						int so;
						FILE *mi;
						printf("INPUT SYSTEM TYPE，Windows TO 0，Android TO 1\n");
						scanf("%d", &so);
						if (so == 0)
						{
							mi = fopen("D:\reader\101.txt", "wt");
							if (mi == NULL)
							{
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf("CAN NOT READ THE FILE！\n");
								system("pause");
							}
							else
							{
								printf("READ COMPLETELY\n");
								printf("%c\n", mi);
								printf("CAL COMPLETELY\n");
							}
						}
						if (so == 1)
						{
							mi = fopen("/mnt/sdcard/101.txt", "wt");
							if (mi == NULL)
							{
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf(" \n");
								printf("CAN NOT READ THE FILE！\n");
								system("pause");
							}
							else
							{
								printf("读取完成\n");
								printf("%c\n", mi);
								printf("显示完毕\n");
							}
						}
						else
						{
							printf("输入错误\n");
							exit;
							exit;
						}
					}
					else
					{
						printf("a=%d,b=%d\n", y, h);
						e = pow(y, h);
						if ((e > 200000000) || (e < -200000000))
						{
							printf("TOO BIG TO CAL \n");
							printf("program is over \n");
							exit;
							exit;
						}
						while (w <= h)
						{
							c = pow(y, w);
							printf("%d的%d次方为%d\n", y, w, c);
							w = w + 1;
						}
						printf("computational completion\n");
						printf("if you want to end this program ");
						printf("just input “0” \n");
						printf("if you want to try again,please input “1”\n");
						printf("伶仃shrink\n");
						printf("帅到飞起的碳酸根咸鱼\n");
						int endcir;
						endcir = 1;
						while (endcir == 1)
						{
							scanf("%d", &r);
							if (r == 0)
							{
								printf("program is over\n");
								endcir = 2;
								q = 999;
								system("cls");
							}
							if (r == 1)
							{
								endcir = 2;
							}
							if ((r != 1) && (r != 0))
							{
								printf("input error");
							}
						}
					}
				}
			}
			if (q == 7)
			{
				system("cls");
				printf("递归示例计算程序\n");
				int digui;
				scanf("%d", &digui);
				digui = fun(digui);
				printf("计算结果%d\n", digui);
				system("pause");
				q = 999;
				system("cls");
			}
			if (q == 6)
			{
				system("cls");
				int toolserr;
				int andtools;
				toolserr = 1;
				while (toolserr == 1)
				{
					printf("\n");
					printf("\n");
					printf("\n");
					printf("\n");
					printf("\n");
					printf("android tools\n");
					printf("1 to busybox\n");
					printf("2 to su\n");
					printf("3 to exit\n");
					scanf("%d", &andtools);
					if (andtools == 1)
					{
						system("busybox");
						toolserr = 0;
					}
					if (andtools == 2)
					{
						system("su");
						toolserr = 0;
					}
					if (andtools == 3)
					{
						q = 999;
						system("cls");
						toolserr = 0;
					}
					if (toolserr == 1)
					{
						printf("retry\n");
					}
				}

			}
			if (q == 1)
			{
				system("cls");
				while (q == 1)
				{
					printf("发声程序\n");
					printf("程序调用WINDOWS BEEP函数\n");
					if(debug==1)
					{printf("DEBUGING\n");}
					if((debug==1)&&(school[23]!=0)&&(school[24]!=0))
					{
						printf("Beep as planned\n");					
					}
					else
					{ 
					int bhz, ehz, hztm, scanjump;
					printf("\n");
					printf("\n输入起始频率\n");
					scanf("%d", &bhz);
					printf("输入终止频率\n");
					scanf("%d", &ehz);
					printf("输入单频播放时间（毫秒）\n");
					scanf("%d", &hztm);
					printf("输入扫描跨度\n");
					scanf("%d", &scanjump);
					printf("已输入从%dHz到%dHz\n", bhz, ehz);
					printf("单频播放%dms\n", hztm);
					if (hztm <= 5)
					{
						printf("输入单频播放时间过短，有可能无法播放\n");
					}
					if((bhz>=20000)||(ehz>=20000)) 
					{
						printf("发声频率包含超声波，能否发出声波同样取决于当前的音频设备性能\n");
					}
					if((bhz<=20)||(ehz<=20))
					{
						printf("发声频率包含次声波，能否发出声波同样取决于当前的音频设备性能\n");
						printf("注意；次声波可能和人体器官的振动频率相近或相同\n");
						printf("响度过大可使心脏出现强烈共振和肺壁受损甚至死亡，请注意\n");
					}
					int addhz, addhzs, addtime;
					addhz = ehz - bhz + 1;
					if (addhz<0)
					{
						printf("已进行负值归正\n");
						addhzs = 0 - addhz;
					}
					else
					{
						addhzs = addhz;
					}
					addtime = addhzs * hztm;
					addtime = addtime / 1000;
					addtime = addtime / scanjump;
					printf("理想状态共需时间%ds\n", addtime);
					printf("按任意键开始播放\n");
					system("pause");
					while (bhz < ehz)
					{
						printf("正在升调发声%d\n", bhz);
						bhz = bhz + scanjump;
					}
					while (ehz < bhz)
					{
						printf("正在降调发声%d\n", bhz);
						bhz = bhz - scanjump;
					}
					if (ehz == bhz)
					{
						printf("正在单调发声%d\n", bhz);
						bhz = bhz - 1;
					}
					} 
					printf
						("运行完毕，输入任意值重启发声程序，结束程序输入0\n");
					int bepover;
					scanf("%d", &bepover);
					if (bepover == 0)
					{
						q = 999;
						system("cls");
					}
				}
			}
			if (q == 3)
			{
				system("cls");
				if (debug == 1)
				{
					printf("程序主界面q为%d\n", q);
				}
				int j, o, f;
				o = 3;
				while (o == 3)
				{
					printf("please input a number to translate the day\n");
					printf("press 999 to exit\n");
					scanf("%d", &j);
					if (j == 999)
					{
						o = 999;
						q = 999;
						printf("exit to menu successfully\n");
						system("cls");
					}
					switch (j)
					{
					case 1:
						printf("MONDAY 星期一\n");
						scanf("%d", &f);
						break;
					case 2:
						printf("TUESDAY 星期二\n");
						scanf("%d", &f);
						break;
					case 3:
						printf("WEDNESDAY 星期三\n");
						scanf("%d", &f);
						break;
					case 4:
						printf("THURSDAY 星期四\n");
						scanf("%d", &f);
						break;
					case 5:
						printf("FRIDAY 星期五\n");
						scanf("%d", &f);
						break;
					case 6:
						printf("SATURDAY 星期六\n");
						scanf("%d", &f);
						break;
					case 7:
						printf("SUNDAY 星期日\n");
						scanf("%d", &f);
						break;
					}
				}
			}
			if (q == 4)
			{
				system("cls");
				if (debug == 1)
				{
					printf("程序主界面q为%d\n", q);
				}
				int y, w, k;
				w = 0;
				printf("THIS IS THE ORIGINAL WORK OF SF\n");
				scanf("%s%d", &y, &k);
				while (w < k)
				{
					printf("%d\n", &y);
					printf("%x\n", &y);
					printf("%f\n", &y);
					w = w + 1;
				}
				printf("computational completion\n");
				w = 1;
				while (w < k)
				{
					printf("%s,too\n", &y);
					w = w + 1;
				}
				printf("THAT IS ALL\n");
				printf("帅到飞起的碳酸根咸鱼\n");
				printf("input 0 to exit\n");
				int playexit;
				scanf("%d", &playexit);
				if (playexit == 0)
				{
					q = 999;
					system("cls");
				}
			}
			if (q == 5)
			{
				system("cls");
				if (debug == 1)
				{
					printf("程序初始主界面q为%d\n", q);
				}
				int cir;
				int a, b, c, n, t, x, tongxlc, tongwhe, aimx, aimy, aimtime, err, h, namecho,
					seatcir, i;
				cir = 1;
				seatcir = 1;
				while (seatcir == 1)
				{
					while (cir == 1)
					{
						err = 1;
						while (err == 1)
						{
							if (debug == 1)
							{
								printf("程序主界面q为%d，cir为%d\n", q, cir);
							}

							printf("请输入当前横排纵列数\n");
							scanf("%d%d", &h, &i);
							a = h;
							b = i;
							printf("请输入时间跨度，单位:周\n");
							scanf("%d", &c);
							t = 0;
							q = 0;
							printf("请输入您当前周数\n");
							scanf("%d", &n);
							if ((a <= 4) && (b <= 6))
							{
								err = 0;
							}
							else
							{
								printf("输入错误\n");
							}
						}
						tongxlc = n + 2;
						while (tongxlc > 4)
						{
							tongxlc = tongxlc - 4;
						}
						if (a == tongxlc)
						{
							tongwhe = 1;
						}
						if ((b == 4) && (a == tongxlc))
						{
							a = a + c;
							while (a > 4)
							{
								a = a - 4;
							}
							printf("您的座位编码是(%d，4)\n", a);
						}
						else
						{
							q = 1;
							while (q <= c)
							{
								b = b + a;
								a = a + 1;
								q = q + 1;
								while (b > 6)
								{
									b = b - 6;
								}
								while (a > 4)
								{
									a = a - 4;
								}
								if (tongwhe == 1)
								{
									while (b == 4)
									{
										b = b + 1;
									}
								}
							}
							printf("您的座位编码为(%d，%d)\n", a, b);
						}
						system("pause");
						printf
							("重新计算输入1，结束程序请输入0，继续计算座位请输入任意值\n");
						scanf("%d", &cir);
					}
					if (cir == 0)
					{
						printf("程序已终止\n");
						system("cls");
						if (debug == 1)
						{
							printf("未退出时q为%d，cir为%d\n", q, cir);
						}
						q = 999;
						cir = 999;
						q = 999;
						seatcir = 999;
						if (debug == 1)
						{
							printf("退出时q为%d，cir为%d\n", q, cir);
						}

					}
					else
					{
						int targeterr;
						targeterr = 1;
						while (targeterr == 1)
						{
							printf("请输入期望横排纵列数\n");
							scanf("%d%d", &aimx, &aimy);
							printf("请输入期望时间段，单位:周\n");
							scanf("%d", &aimtime);
							if ((aimx <= 4) && (aimy <= 6))
							{
								targeterr = 0;
							}
							else
							{
								printf("输入错误\n");
							}
						}
						int sss, ungetrtn;
						sss = 0;
						ungetrtn = 0;
						a = h;
						b = i;
						if ((tongwhe == 1) && (b == 4))
						{
							while (sss < aimtime)
							{
								a = a + 1;
								while (a > 4)
								{
									a = a - 4;
								}
								if ((a == aimx) && (b == aimy))
								{
									printf("%d周后可达目标位置\n", sss + 1);
									ungetrtn = 1;
								}
								sss = sss + 1;
							}
						}
						else
						{
							ungetrtn = 0;
							while (sss < aimtime)
							{
								b = b + a;
								a = a + 1;
								while (b > 6)
								{
									b = b - 6;
								}
								while (a > 4)
								{
									a = a - 4;
								}
								while (b == 4)
								{
									b = b + 1;
								}
								if ((a == aimx) && (b == aimy))
								{
									printf("%d周后可达目标位置\n", sss + 1);
									ungetrtn = 1;
								}
								sss = sss + 1;
							}
						}
						if (ungetrtn == 0)
						{
							printf("在所指定范围内没有机会坐到该座位\n");
						}
						printf("按任意键进行座位推算plus\n");
						system("pause");
						namecho = 1;
					}
					if (namecho == 1)
					{
						int aax, aay, abx, aby, acx, acy, adx, ady;
						int aex, aey, afx, afy;
						int bax, bay, bbx, bby, bcx, bcy, bdx, bdy;
						int bex, bey, bfx, bfy;
						int cax, cay, cbx, cby, ccx, ccy, cdx, cdy;
						int cex, cey, cfx, cfy;
						int dax, day, dbx, dby, dcx, dcy, ddx, ddy;
						int dex, dey, dfx, dfy;
						aax = 1;
						abx = 1;
						acx = 1;
						adx = 1;
						aex = 1;
						afx = 1;
						bax = 2;
						bbx = 2;
						bcx = 2;
						bdx = 2;
						bex = 2;
						bfx = 2;
						cax = 3;
						cbx = 3;
						ccx = 3;
						cdx = 3;
						cfx = 3;
						cex = 3;
						dax = dbx = dcx = ddx = dex = dfx = 4;
						aay = bay = cay = day = 1;
						aby = bby = cby = dby = 2;
						acy = bcy = ccy = dcy = 3;
						ady = bdy = cdy = ddy = 4;
						aey = bey = cey = dey = 5;
						afy = bfy = cfy = dfy = 6;
						int fqu = 0;
						int chax;
						chax = c + n - 3;
						while (fqu <= chax)
						{
							ady = 4;
							aay = aay + aax;
							aby = aby + abx;
							acy = acy + acx;
							ady = ady + adx;
							aey = aey + aex;
							afy = afy + afx;
							bay = bay + bax;
							bby = bby + bbx;
							bcy = bcy + bcx;
							bdy = bdy + bdx;
							bfy = bfy + bfx;
							bey = bey + bex;
							cay = cay + cax;
							cby = cby + cbx;
							ccy = ccy + ccx;
							cdy = cdy + cdx;
							cey = cey + cex;
							cfy = cfy + cfx;
							day = day + dax;
							dby = dby + dbx;
							dcy = dcy + dcx;
							ddy = ddy + ddx;
							dey = dey + dex;
							dfy = dfy + dfx;
						}
						printf("作者编写中，抱歉\n");
						namecho = 5;
						cir = 1;
						system("pause");
						system("cls");
					}
				}
			}
		}
	}
}
