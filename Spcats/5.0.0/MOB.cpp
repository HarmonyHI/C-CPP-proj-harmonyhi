#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int Sleep(int st)
{
	int headrec, headnow, headmark = 0;
	st = st * 100000;
	while (headmark <= st)
	{
		time_t t;
		headrec = t;
		headnow = t;
		if (headrec == headnow)
		{
			headmark = headmark + 1;
		}
	}
}

int Beep(falsebeepa, falsebeepb)
{
	printf("Windows system dealing data(%d %d)\n", falsebeepa, falsebeepb);
}

int fun(int x)
{
	if (x > 1)
		return x + fun(x - 1);
	else
		return x;
}

#define NTXTREADY 255			/* 假定文章的总行数不超过255，可更改 
								 */
int ctrldatabase[100];
int txtwrite(txtwriter)
{
	{
		int uui = 1;
		int iwt = 0, maxTXTREAD, TXTREADY, extraier = 0;
		system("mkdir /sdcard/NSDData");
		char stxt[NTXTREADY][100], *ptxt, *qtxt = "/sdcard/NSDData/CTDATA.txt";
		FILE *fptxt;
		if ((fptxt = fopen("/sdcard/NSDData/CTDATA.txt", "w+")) == NULL)
		{
			printf("Open file %s error!", qtxt);
			getch();
		}

		while (extraier < 100)
		{

			while (iwt < 0 && fgets(ctrldatabase[iwt], 101, fptxt) != NULL)
			{
				ptxt = strchr(ctrldatabase[iwt], '\n');
				if (ptxt)
					*ptxt = '\0';	/* 消除每行最后的回车符 */
				iwt++;
			}
			strcpy(stxt[iwt++], ctrldatabase);	/* 插入到第一行 */

			while (iwt < NTXTREADY && fgets(stxt[iwt], 101, fptxt) != NULL)	/* 继续读原文章 
																			 */
			{
				ptxt = strchr(stxt[iwt], '\n');
				if (ptxt)
					*ptxt = '\0';
				iwt++;
			}
			maxTXTREAD = iwt;	/* max为文章实际的总行数 */
			rewind(fptxt);

			for (iwt = 0; iwt < maxTXTREAD; iwt++)
			{
				fprintf(fptxt, "%d\n", ctrldatabase[iwt]);	/* 输出到文件a.txt中 
														 */
			}
			extraier = extraier + 1;
		}
		{
			printf("OUTPUT SUCCESS\n");
		}
		fclose(fptxt);
		getch();
	}
}

int timesigner(int tsgninput)
{
	int timenow, t, b, year, month, day, hour, minute, second;
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
	day = lt->tm_mday;
	year = lt->tm_year + 1900;
	month = lt->tm_mon + 1;
	hour = b;
	minute = lt->tm_min;
	second = lt->tm_sec;
	timenow = 60 * 60 * 24 * day + 60 * 60 * hour + 60 * minute + second;
	return timenow;
}

int Datareader(sewhat)
{
	int sewhatdata = 1;
	while (sewhatdata <= 100)
	{
		ctrldatabase[sewhatdata - 1] = wordread(sewhatdata);
		sewhatdata = sewhatdata + 1;
	}
}

int wordread(whichLine)
{
	whichLine = whichLine - 1;
	FILE *datafile;
	int intlikenum;
	int currentLine = 0, foundpotsen = 0;
	char strLine[1024];
	if ((datafile = fopen("/sdcard/NSDData/CTDATA.txt", "r")) == NULL)
	{
		printf("NO CTDATA!\n");
		return NULL;
	}
	while (foundpotsen == 0)
	{

		if (currentLine == whichLine)
		{
			fgets(strLine, 1024, datafile);
			intlikenum = atoi(strLine);
			return intlikenum;
			foundpotsen = 1;
		}
		fgets(strLine, 1024, datafile);
		currentLine = currentLine + 1;
	}
	fclose(datafile);
}

int syncpic(hankind, hanx, hany, hanpx, hanpy)
{
	int a = 0;
	double pic[60], mathy, mathx;
	while (a < 60)
	{
		mathx = hanx * (0.2 * a - 6 + hanpx);
		if (hankind == 0)
		{
			mathy = sin(mathx);
		}
		if (hankind == 1)
		{
			mathy = log(mathx);
		}
		if (hankind == 2)
		{
			mathy = mathx * mathx;
		}
		if (hankind == 3)
		{
			mathy = mathx * mathx * mathx;
		}
		if (hankind == 4)
		{
			mathy = 1 / mathx;
		}
		pic[a] = 3 * hany * mathy + 16 + hanpy;
		a = a + 1;
	}
	a = 0;
	int mathx = 0, mathy = 30, s;
	while (mathy >= 0)
	{
		s = pic[mathx];
		if (mathy == s)
		{
			printf("@");
		}
		if (mathy != s)
		{
			if (mathy == 16)
			{
				printf(".");
			}
			else
			{
				printf(".");
			}
		}

		mathx = mathx + 1;
		if (mathx == 30)
		{
			printf(" ");
		}
		if (mathx == 60)
		{
			printf("\n");
			mathy = mathy - 1;
			mathx = 0;
		}
	}
}

int name(xname)
{
	if (xname == 1)
	{
		printf("AS8214\n");
	}
	if (xname == 2)
	{
		printf("NS5407\n");
	}
	if (xname == 3)
	{
		printf("SWE7099\n");
	}
}

int words(girlwords)
{
	int bytimeword = 0;
	srand(time(0));
	bytimeword = rand() % 5 + 1;
	if (girlwords == 1)
	{
		if (bytimeword == 1)
		{
			printf("测试语1\n");
		}
		if (bytimeword == 2)
		{
			printf("测试语b\n");
		}
		if (bytimeword == 3)
		{
			printf("测试语c\n");
		}
		if (bytimeword == 4)
		{
			printf("测试语d\n");
		}
		if (bytimeword == 5)
		{
			printf("测试语e\n");
		}
	}
	if (girlwords == 2)
	{
		if (bytimeword == 1)
		{
			printf("测试语aa\n");
		}
		if (bytimeword == 2)
		{
			printf("测试语bb\n");
		}
		if (bytimeword == 3)
		{
			printf("测试语cc\n");
		}
		if (bytimeword == 4)
		{
			printf("测试语dd\n");
		}
		if (bytimeword == 5)
		{
			printf("测试语ee\n");
		}
	}
	if (girlwords == 3)
	{
		if (bytimeword == 1)
		{
			printf("测试语aaa\n");
		}
		if (bytimeword == 2)
		{
			printf("测试语bbb\n");
		}
		if (bytimeword == 3)
		{
			printf("测试语ccc\n");
		}
		if (bytimeword == 4)
		{
			printf("测试语ddd\n");
		}
		if (bytimeword == 5)
		{
			printf("测试语eee\n");
		}
	}
}

int emoji(in)
{
	if (in == 1)
	{
		printf("(｡•̀ᴗ-)✧\n");
	}
	if (in == 2)
	{
		printf("(⁎˃ᆺ˂)\n");
	}
	if (in == 3)
	{
		printf("(´◉.◉)\n");
	}
	if (in == 4)
	{
		printf("(｀⌒´メ)\n");
	}
	if (in == 5)
	{
		printf("( •̣̣̣̣̣̥́௰•̣̣̣̣̣̥̀ )\n");
	}
	if (in == 6)
	{
		printf("( ♡д♡)\n");
	}
}

int main(systemlink)
{
	int q, menucir, menuerr, debug;
	int ctrldatabasecir, schsync, location, file, password;
	int ctrldatabasepl[100];
	int autotest = 0;
	int xxx = 0, beginning = 0;
	int yyy = 0, beginningpl = 0;
	int menuchose = 1;
	debug = 0;
	int freecho, petheart, petmood, petsex, pethungry, petclean, pettype, girlage, matter,
		boylevel, bathsex, hugsex, parksex, userchogirl, money, bread, sextool, bathtool, funtool,
		girlname, exp =
		0, returnbill, expegg, heartdrop, sexup, sexdrop, mooddrop, goodsnumber, sexaaa, sexaab,
		sexaac, sexaad, touchcounter, sextop, sexnow, sextoolhistory, touchlocate, regmenucirchk =
		0, superuser = 0;
	srand(time(0));
	while (beginning <= 100)
	{
		ctrldatabase[xxx] = 0;
		xxx = xxx + 1;
		beginning = beginning + 1;
	}
	while (beginningpl <= 100)
	{
		ctrldatabasepl[yyy] = 0;
		yyy = yyy + 1;
		beginningpl = beginningpl + 1;
	}
	menucir = 2;
	while (menucir == 2)
	{
		menuerr = 1;
		while (menuerr == 1)
		{
			system("cls");
			xxx = 30, yyy = 30;
			if (superuser == 1)
			{
				while (xxx <= 44)
				{
					ctrldatabase[yyy] = 1;
					xxx = xxx + 1;
					yyy = yyy + 1;
				}
			}
			if (debug == 1)
			{
				printf("DEBUGMODE ON\n");
			}
			if (ctrldatabase[30] == 1)
			{
				printf("     1 to Beep program\n");
			}
			if (ctrldatabase[31] == 1)
			{
				printf("     2 to Pow calculator\n");
			}
			if (ctrldatabase[32] == 1)
			{
				printf("     3 to Week calculator\n");
			}
			if (ctrldatabase[33] == 1)
			{
				printf("     4 to Egg\n");
			}
			if (ctrldatabase[34] == 1)
			{
				printf("     5 to Seat calculator\n");
			}
			if (ctrldatabase[35] == 1)
			{
				printf("     6 to Android tool box\n");
			}
			if (ctrldatabase[36] == 1)
			{
				printf("     7 to Cir cal\n");
			}
			if (debug == 1)
			{
				printf("     8 to Data controller\n");
			}
			if (debug != 1)
			{
				printf("     8 to Data Container\n");
			}
			if (ctrldatabase[38] == 1)
			{
				printf("     9 to Timer\n");
			}
			if (ctrldatabase[39] == 1)
			{
				printf("    10 to Game\n");
			}
			printf("    11 to Dis/Enable debug mode\n");
			if (ctrldatabase[41] == 1)
			{
				printf("    12 to Pet raising game\n");
			}
			if (ctrldatabase[42] == 1)
			{
				printf("    13 to Math drawer\n");
			}
			if (ctrldatabase[43] == 1)
			{
				printf("    14 to Music player\n");
			}
			if (ctrldatabase[44] == 1)
			{
				printf("    15 to Clutr ablty rate\n");
			}
			if (debug == 1)
			{
				printf("    1123 to autotest\n\n\n");
			}
			printf("PRESS KEY TO CHOOSE FOUCTIONS\n");
			scanf("%d", &q);
			if (((q == 1) && (ctrldatabase[30] == 1)) || ((q == 2) && (ctrldatabase[31] == 1))
				|| ((q == 3) && (ctrldatabase[32] == 1)) || ((q == 4) && (ctrldatabase[33] == 1)) || ((q == 5)
																						  &&
																						  (ctrldatabase
																						   [34] ==
																						   1))
				|| ((q == 6) && (ctrldatabase[35] == 1)) || ((q == 7) && (ctrldatabase[36] == 1)) || (q == 11)
				|| ((q == 15) && (ctrldatabase[44] == 1)) || ((q == 13) && (ctrldatabase[42] == 1))
				|| ((q == 14) && (ctrldatabase[43] == 1)) || (q == 8) || ((q == 9) && (ctrldatabase[38] == 1))
				|| ((q == 10) && (ctrldatabase[39] == 1)) || ((q == 1123) && (debug == 1)) || ((q == 12)
																						 &&
																						 (ctrldatabase
																						  [41] ==
																						  1)))
				
			{
				menuerr = 0;
			}
			if ((q != 5) && (q != 4) && (q != 8) && (q != 6) && (q != 14) && (q != 15) && (q != 3)
				&& (q != 2) && (q != 9) && (q != 13) && (q != 1) && (q != 7) && (q != 10)
				&& (q != 11) && ((q != 1123) && (q != 12)))
			{
				printf("input error and try again\n");
				system("pause");
				system("cls");
			}
			if ((q == 1123) && (debug != 1))
			{
				printf("input error and try again\n");
				system("pause");
				system("cls");
			}
			regmenucirchk = ctrldatabase[q + 29];
			if ((q != 8) && (q != 11) && (q > 0) && (q <= 15) && (regmenucirchk != 1))
			{
				printf("input error and try again\n");
				system("pause");
				system("cls");
			}
			if (q == 11)
			{
				if (debug == 1)
				{
					debug = 0;
				}
				else
				{
					printf("INPUT PASSWORD\n");
					scanf("%d", &password);
					if (password == 1848030850)
					{
						debug = 1;
						printf("Welcome\n");
						system("pause");
					}
					if (password == 5201314)
					{
						debug = 1;
						superuser = 1;
						printf("LOVELY SEASON\n");
						sleep(1);
						printf("LOVELY YOU\n");
						sleep(1);
						printf("All functions are enabling...\n");
						sleep(2);
						printf("Okay!\n");
						sleep(1);
						system("pause");
					}
					if (password == 94705972)
					{
						txtwrite(0);
						printf("ALLDATA SAVED\n");
						system("pause");
					}
					if (password == 90788445)
					{
						Datareader(0);
						printf("Data Loaded!\n");
						system("pause");
					}
					if ((password != 90788445) && (password != 94705972)
						&& (password != 1848030850) && (password != 5201314))
					{
						printf("WRONG\n");
						system("pause");
					}
				}
			}
			if ((q == 1123) && (debug == 1))
			{
				printf("Auto Test WILL BEGIN\n");
				printf("Debug mode open\n");
				Sleep(500);
				printf("3\n");
				Sleep(1000);
				printf("2\n");
				Sleep(1000);
				printf("1\n");
				Sleep(1000);
				autotest = 1;
				debug = 1;
				menuerr = 0;
			}
		}
		while ((q == 1) || (q == 2) || (q == 6) || (q == 3) || (q == 4) || (q == 7) || (q == 9)
			   || (q == 13) || (q == 14) || (q == 15) || (q == 8) || (q == 5) || (q == 10)
			   || (q == 1123) || (q == 12))
		{
			if ((q == 15) || (autotest == 1))
			{

				system("cls");
				int quizstrength, quiztimea, quiztimeb, deltatime, ingstrength = 1, calcore =
					1, ingchecker = 0, ingbeep = 0, printbugfixaa = 0, printbugfixab =
					0, printbugfixac = 0, printbugfixad = 0;
				printf("设备运算性能评估v1.0\n\n\n\n");
				printf("请键入测试强度(约50-100)\n");
				if (autotest != 1)
				{
					scanf("%d", &quizstrength);
				}
				if (autotest == 1)
				{
					quizstrength = 80;
				}
				if (quizstrength > 100)
				{
					printf("您选择了增强难度，设备可能卡机\n");
				}
				if (quizstrength < 50)
				{
					printf("您选择了弱鸡强度，测试结果可能有较大误差\n");
				}
				printf("Test starting...\n");
				Sleep(1300);
				quizstrength = quizstrength * 500000;

				quiztimea = timesigner(1);
				while (ingstrength < quizstrength)
				{
					printbugfixaa = ingstrength % 500000;
					if (printbugfixaa == 1)
					{
						system("cls");
						printbugfixab = ingstrength / 5000;
						printbugfixab = printbugfixab + 1;
						printbugfixac = quizstrength / 500000;
						printbugfixad = printbugfixab / printbugfixac;

						printf("正在测试(%d％已完成)\n", printbugfixad + 1);

					}

					calcore = calcore + 3;
					calcore = calcore - 1;
					calcore = log(calcore);
					calcore = calcore * calcore;
					ingstrength = ingstrength + 1;
				}
				system("cls");
				quiztimeb = timesigner(1);
				deltatime = quiztimeb - quiztimea;
				deltatime = quizstrength / deltatime;
				deltatime = deltatime / 10;
				printf("测试结果 %d\n", deltatime);
				if (autotest != 1)
				{
					system("pause");
				}
				if (autotest == 1)
				{
					Sleep(1000);
				}
				q = 999;

			}
			if ((q == 9) || (autotest == 1))
			{
				int goaltime;
				int timeold;
				int timecir = 1;
				int timemenucir = 0;
				int timemach = 0;
				int timenow = 0;
				int alarmdata;
				int alarmcho;
				int ambcho = 0;
				int lasttime;
				int alarm = 0;
				int maker = 0;
				int b;
				int checker = 0;
				int beepcho = 1;
				int year, month, day, hour, minute, second;
				while (timemenucir == 0)
				{
					system("cls");
					printf("Press 1 to alarm,2 to timer only ,others to back main menu\n");
					printf("Warnning:TIMER could NOT back to any menu\n");
					if (autotest == 0)
					{
						scanf("%d", &ambcho);
					}
					else
					{
						Sleep(300);
						ambcho = 1;
					}
					if ((ambcho != 1) || (ambcho != 2))
					{
						q = 999;
						timemenucir = 1;
						system("cls");
					}
					printf("LOADING......\n");
					Sleep(300);
					system("cls");
					if (ambcho == 1)
					{
						printf("Input goal time (second)\n");
						if (autotest == 0)
						{
							scanf("%d", &goaltime);
						}
						else
						{
							goaltime = 3;
						}
						printf("Beep when times up？(0 to choose)\n");
						if (autotest == 0)
						{
							scanf("%d", &beepcho);
						}
						else
						{
							beepcho = 0;
						}
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
								timenow =
									60 * 60 * 24 * day + 60 * 60 * hour + 60 * minute + second;

								if (timenow - timeold == goaltime)
								{
									system("cls");
									printf("TIMES UP\n");
									if (beepcho == 0)
									{
										if ((debug == 1) && (ctrldatabase[23] != 0) && (ctrldatabase[24] != 0))
										{
											Beep(ctrldatabase[23], ctrldatabase[24]);
										}
										else
										{
											Beep(500, 2000);
										}
									}
									if (autotest == 0)
									{
										system("pause");
									}
									printf("Continue timer(any) or exit alarm(0) ?\n");
									printf("Warnning:TIMER could NOT back to any menu\n");
									ambcho = 2;
									if (debug == 1)
									{
										printf("DEBUG LOG\n");
										printf("goaltime:%d\n", goaltime);
										printf("timeold:%d\n", timeold);
										printf("timecir:%d\n", timecir);
										printf("timemenucir:%d\n", timemenucir);
										printf("alarmdata:%d\n", alarmdata);
										printf("ambcho:%d\n", ambcho);
										printf("timemach:%d\n", timemach);
										printf("timenow:%d\n", timenow);
										printf("maker:%d\n", maker);
										printf("alarm:%d\n", alarm);
										printf("b:%d\n", b);
										printf("checker:%d\n", checker);
										printf("year:%d\n", year);
										printf("month:%d\n", month);
										printf("day:%d\n", day);
										printf("hour:%d\n", hour);
										printf("minute:%d\n", minute);
										printf("second:%d\n", second);
										printf("alarmcho:%d\n", alarmcho);
										printf("q:%d\n", q);
										if (autotest == 1)
										{
											Sleep(1200);
										}
									}
									if (autotest == 0)
									{
										scanf("%d", &alarmcho);
									}
									else
									{
										Sleep(200);
										alarmcho = 0;
										autotest = 2;
									}
									if (alarmcho == 0)
									{
										ambcho = 999;
										timecir = 999;
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
									if (ambcho == 1)
									{
										lasttime = goaltime - (timenow - timeold);
										printf("REMAIN TIME:%d\n", lasttime);
									}
								}
								checker = second;
							}
						}
					}
				}
			}
			if (q == 12)
			{
				menuchose = 0;
				petheart = ctrldatabase[1];
				pethungry = ctrldatabase[2];
				petsex = ctrldatabase[3];
				petclean = ctrldatabase[4];
				petmood = ctrldatabase[5];
				exp = ctrldatabase[6];
				girlage = ctrldatabase[7];
				sextool = ctrldatabase[8];
				bathtool = ctrldatabase[9];
				funtool = ctrldatabase[10];
				bread = ctrldatabase[11];
				money = ctrldatabase[12];
				if (exp == 0)
				{
					petheart = 100;
					petmood = 100;
					petsex = 100;
					pethungry = 100;
					petclean = 100;
					pettype = 0;
					matter = 0;
					boylevel = 0;
					bathsex = 0;
					hugsex = 0;
					money = 100;
					parksex = 0;
					bread = 0;
					sextool = 0;
					girlname = 0;
					bathtool = 0;
					funtool = 0;
					returnbill = 0;
					expegg = 0;
					heartdrop = 0;
					sexdrop = 0;
					sexup = 0;
					mooddrop = 0;
					goodsnumber = 0;
					sexaaa = 0;
					sexaab = 0;
					sextoolhistory = 0;
					sexaac = 0;
					sexnow = 0;
					sexaad = 0;
					girlage = rand() % 5 + 14;
					girlname = rand() % 3 + 1;
					printf("LOADING...\n");
					Sleep(1000);
					system("cls");
					printf("领取到一个%d个月的小动物\n", girlage);
					Sleep(1000);
					printf("你把他起名为\n");
					name(girlname);
					words(girlname);
					if (girlname == 1)
					{
						heartdrop = 10;
						sexdrop = 15;
						sexup = 20;
						mooddrop = 8;
						sextop = 30;
					}
					if (girlname == 2)
					{
						heartdrop = 15;
						sexdrop = 8;
						sexup = 12;
						mooddrop = 7;
						sextop = 20;
					}
					if (girlname == 3)
					{
						sexdrop = 30;
						sexup = 19;
						mooddrop = 15;
						heartdrop = 29;
						sextop = 50;
					}
					printf("\n");
					exp = exp + 1;
				}
				system("pause");
				while ((exp > 0) && (menuchose == 0))
				{
					system("cls");
					if (petsex < 0)
					{
						petsex = 0;
						printf(" 找过来\n");
						Sleep(1000);
						while (sexnow < sextop)
						{
							printf("1:头\n2:握手\n3:亲吻\n4:顺毛\n");
							scanf("%d", &touchlocate);
							if (touchlocate == 1)
							{
								printf("头\n");
								sexaaa = sexaaa + 5;
								sexnow = sexnow + 4;
							}
							if (touchlocate == 2)
							{
								printf("握手\n");
								sexaab = sexaab + 5;
								sexnow = sexnow + 8;
							}
							if (touchlocate == 3)
							{
								printf("亲吻\n");
								sexaac = sexaac + 12;
								sexnow = sexnow + 9;
							}
							if (touchlocate == 4)
							{
								printf("顺毛\n");
								if ((girlage <= 15) && (sexaad == 0))
								{
									printf("初识主人\n");
								}
								sexaad = sexaad + 14;
								sexnow = sexnow + 11;
							}

						}
						petsex = petsex + 55;
						printf("它走开了\n");
						system("pause");
						sexnow = 0;
						printf("生命(前)%d", petheart);
						petheart = petheart - heartdrop * (16 - girlage);
						printf("生命(后)%d", petheart);


					}
					if ((exp > 100) && (expegg == 0))
					{
						printf("100经验奖励\n");
						expegg = expegg + 1;
						sextop = sextop + 20;
						system("pause");
					}
					if ((exp > 500) && (expegg == 1))
					{
						printf("500经验奖励\n");
						expegg = expegg + 1;
						sextop = sextop + 20;
						system("pause");
					}
					if ((exp > 800) && (expegg == 2))
					{
						printf("800经验奖励\n");
						expegg = expegg + 1;
						sextop = sextop + 50;
						system("pause");
					}
					if (pethungry <= 0)
					{
						pethungry = 0;
						printf("饥饿制病.\n");
						petheart = petheart - heartdrop;
					}
					if (petclean < 0)
					{
						printf("脏.\n");
						petheart = petheart - 0.5 * heartdrop;
					}
					if (petmood < 0)
					{
						printf("郁闷.\n");
						petheart = petheart - 0.8 * heartdrop;
					}

					freecho = rand() % 8 + 1;
					if (exp > 20)
					{
						if (freecho == 1)
						{
							printf("掉血.\n");
							petheart = petheart - heartdrop;
						}
						if ((freecho == 2) && (exp > 50))
						{
							printf("出去玩.\n");
							petclean = petclean - 10;
							petmood = petmood + mooddrop;
							if (sextool >= 1)
							{
								printf("PLAY0\n");
								petsex = petsex + 0.6 * sexup;
								sextool = sextool - 1;
							}
						}
						if (freecho == 3)
						{
							printf("受伤.\n");
							petsex = petsex - 1.5 * sexdrop;
						}
						if (freecho == 4)
						{
							printf("生病.\n");
							petheart = petheart - heartdrop;
						}
						if (freecho == 5)
						{
							printf("生气.\n");
							petmood = petmood - mooddrop;
						}
						if (freecho == 6)
						{
							printf("劳累.\n");
							petheart = petheart - 0.2 * heartdrop;
							petmood = petmood - 0.6 * mooddrop;
							petsex = petsex - 0.4 * sexdrop;
						}
						if (freecho == 7)
						{
							printf("饿\n");
							pethungry = pethungry - 10;
						}
						if (freecho == 8)
						{
							printf("突然开心\n");
							while (sexnow < sextop)
							{
								printf("1:头\n2:握手\n3:亲吻\n4:顺毛\n");
								scanf("%d", &touchlocate);
								if (touchlocate == 1)
								{
									printf("头\n");
									sexaaa = sexaaa + 5;
									sexnow = sexnow + 4;
								}
								if (touchlocate == 2)
								{
									printf("握手\n");
									sexaab = sexaab + 5;
									sexnow = sexnow + 8;
								}
								if (touchlocate == 3)
								{
									printf("亲吻\n");
									sexaac = sexaac + 12;
									sexnow = sexnow + 9;
								}
								if (touchlocate == 4)
								{
									printf("顺毛\n");
									if ((girlage <= 15) && (sexaad == 0))
									{
										printf("初识主人\n");
									}
									sexaad = sexaad + 14;
									sexnow = sexnow + 11;
								}

							}
							sexnow = 0;
							printf("它走开了\n");
							system("pause");
							petsex = petsex + 0.85 * sexup;
						}
					}
					if (money < 0)
					{
						printf("你已欠债%d元\n", 0 - money);
						printf("即将还债\n");
						returnbill = 1;
					}
					if (money >= 0)
					{
						returnbill = 0;
					}
					if (petsex < 50)
					{
						printf("状态:饥渴");
						emoji(1);
					}
					if (pethungry < 50)
					{
						printf("状态:饥饿");
						emoji(2);
					}
					if (petclean < 50)
					{
						printf("状态:脏");
						emoji(3);
					}
					if (petmood < 50)
					{
						printf("状态:郁闷");
						emoji(4);
					}
					if (petheart < 50)
					{
						printf("状态:生病");
						emoji(5);
					}
					if (petheart < 0)
					{
						exp = 0;
						printf("已死亡\n");
						Sleep(5000);
						system("pause");
						system("cls");
					}
					if ((petheart > 0) && (menuchose == 0) && (returnbill == 0))
					{
						srand(time(0));
						matter = rand() % 6 + 1;
						if (matter == 1)
						{
							printf("和路人搭讪\n");
							srand(time(0));
							boylevel = rand() % 15 + 10;
							petsex = petsex + boylevel * 0.05 * sexup;
							if (boylevel <= 12)
							{
								printf("level 1\n");
							}
							if ((boylevel > 12) && (boylevel <= 20))
							{
								printf("level 2\n");
							}
							if ((boylevel > 20) && (boylevel <= 25))
							{
								printf("level 3\n");
							}
							system("pause");
						}
						if (matter == 2)
						{
							printf(" 商店\n");
							int userbuy = 0;
							exp = exp + 5;
							printf
								("选择物品\n1，顺毛器\n2，面包\n3，沐浴露\n4，玩具\n");
							scanf("%d", &userbuy);
							if ((userbuy >= 1) && (userbuy <= 4))
							{
								if (userbuy == 1)
								{
									printf("数量\n");
									scanf("%d", &goodsnumber);
									money = money - 15 * goodsnumber;
									sextool = sextool + goodsnumber;
									printf("顺毛器已购买%d个，现有%d个\n", goodsnumber,
										   sextool);
								}
								if (userbuy == 2)
								{
									printf("数量\n");
									scanf("%d", &goodsnumber);
									money = money - 10 * goodsnumber;
									bread = bread + goodsnumber;
									printf("面包已购买%d个，现有%d个\n", goodsnumber,
										   bread);
								}
								if (userbuy == 3)
								{
									printf("数量\n");
									scanf("%d", &goodsnumber);
									money = money - 15 * goodsnumber;
									bathtool = bathtool + goodsnumber;
									printf("沐浴露已购买%d个，现有%d个\n", goodsnumber,
										   bathtool);
								}
								if (userbuy == 4)
								{
									printf("数量\n");
									scanf("%d", &goodsnumber);
									money = money - 15 * goodsnumber;
									funtool = funtool + goodsnumber;
									printf("玩具已购买%d个，现有%d个\n", goodsnumber,
										   funtool);
								}
							}
							else
							{
								printf("什么也没买\n");
							}
							printf("钱包余额:%d\n", money);
							system("pause");
							system("cls");
						}
						if (matter == 3)
						{
							printf(" 洗澡\n");
							exp = exp + 10;
							srand(time(0));
							bathsex = rand() % 2 + 1;
							if ((bathsex == 2) && (petsex >= 80))
							{
								printf("BATH0\n");
								while (sexnow < sextop)
								{
									printf("1:头\n2:握手\n3:亲吻\n4:顺毛\n");
									scanf("%d", &touchlocate);
									if (touchlocate == 1)
									{
										printf("头\n");
										sexaaa = sexaaa + 5;
										sexnow = sexnow + 4;
									}
									if (touchlocate == 2)
									{
										printf("握手\n");
										sexaab = sexaab + 5;
										sexnow = sexnow + 8;
									}
									if (touchlocate == 3)
									{
										printf("亲吻\n");
										sexaac = sexaac + 12;
										sexnow = sexnow + 9;
									}
									if (touchlocate == 4)
									{
										printf("顺毛\n");
										if ((girlage <= 15) && (sexaad == 0))
										{
											printf("初识主人\n");
										}
										sexaad = sexaad + 14;
										sexnow = sexnow + 11;
									}
								}
								sexnow = 0;
								printf("它走开了\n");
								system("pause");
								exp = exp + 20;
								petsex = petsex + 1.1 * sexup;
							}
							petclean = petclean + 14;
							system("pause");
						}
						if (matter == 4)
						{
							printf(" 餐厅\n");
							pethungry = pethungry + 30;
							money = money - 20;
							exp = exp + 5;
							printf("钱包余额:%d\n", money);
							system("pause");
						}
						if (matter == 5)
						{
							printf(" 公园\n");
							exp = exp + 10;
							system("pause");
							srand(time(0));
							parksex = rand() % 2 + 1;
							if ((parksex == 2) && (petsex >= 150) && (sextool >= 1))
							{
								printf("PARK0\n");
								while (sexnow < sextop)
								{
									printf("1:头\n2:握手\n3:亲吻\n4:顺毛\n");
									scanf("%d", &touchlocate);
									if (touchlocate == 1)
									{
										printf("头\n");
										sexaaa = sexaaa + 5;
										sexnow = sexnow + 4;
									}
									if (touchlocate == 2)
									{
										printf("握手\n");
										sexaab = sexaab + 5;
										sexnow = sexnow + 8;
									}
									if (touchlocate == 3)
									{
										printf("亲吻\n");
										sexaac = sexaac + 12;
										sexnow = sexnow + 9;
									}
									if (touchlocate == 4)
									{
										printf("顺毛\n");
										if ((girlage <= 15) && (sexaad == 0))
										{
											printf("初识主人\n");
										}
										sexaad = sexaad + 14;
										sexnow = sexnow + 11;
									}
								}
								sexnow = 0;
								printf("它走开了\n");
								system("pause");
								exp = exp + 20;
								petsex = petsex + 0.95 * sexup;
								sextool = sextool - 1;
							}
						}
						if (matter == 6)
						{
							printf(" 拥抱\n");
							exp = exp + 5;
							srand(time(0));
							hugsex = rand() % 2 + 1;
							if ((hugsex == 2) && (petsex >= 80))
							{
								printf("HUG0\n");
								while (sexnow < sextop)
								{
									printf("1:头\n2:握手\n3:亲吻\n4:顺毛\n");
									scanf("%d", &touchlocate);
									if (touchlocate == 1)
									{
										printf("头\n");
										sexaaa = sexaaa + 5;
										sexnow = sexnow + 4;
									}
									if (touchlocate == 2)
									{
										printf("握手\n");
										sexaab = sexaab + 5;
										sexnow = sexnow + 8;
									}
									if (touchlocate == 3)
									{
										printf("亲吻\n");
										sexaac = sexaac + 12;
										sexnow = sexnow + 9;
									}
									if (touchlocate == 4)
									{
										printf("顺毛\n");
										if ((girlage <= 15) && (sexaad == 0))
										{
											printf("初识主人\n");
										}
										sexaad = sexaad + 14;
										sexnow = sexnow + 11;
									}
								}
								sexnow = 0;
								printf("它走开了\n");
								system("pause");
								exp = exp + 10;
								petsex = petsex + sexup;
							}
							system("pause");
						}
						printf
							("生命%d\n饱腹感%d\n毛%d\n清洁%d\n情绪%d\n经验值%d\n钱包余额%d\n头亲近度%d\n握手亲近度%d\n亲近度%d\n毛顺度%d\n娱乐上限%d\n",
							 petheart, pethungry, petsex, petclean, petmood, exp, money, sexaaa,
							 sexaab, sexaac, sexaad, sextop);
						printf
							("1 to wool maker\n2 to bath\n3 to store\n4 to money\n5 to menu\n6 to hospital\n7 to kitchen\nOther to skip activity\n");
						scanf("%d", &userchogirl);
						if (userchogirl == 1)
						{
							if (sextool > 0)
							{
								printf("use tool\n");
								petsex = petsex + 2 * sexup;
								sextop = sextop + 30;
								sextoolhistory = 1;
								sextool = sextool - 1;
							}
							if (sextool == 0)
							{
								petsex = petsex + 0.7 * sexup;
							}
							while (sexnow < sextop)
							{
								printf("1:头\n2:握手\n3:亲吻\n4:顺毛\n");
								scanf("%d", &touchlocate);
								if (touchlocate == 1)
								{
									printf("头\n");
									sexaaa = sexaaa + 5;
									sexnow = sexnow + 4;
								}
								if (touchlocate == 2)
								{
									printf("握手\n");
									sexaab = sexaab + 5;
									sexnow = sexnow + 8;
								}
								if (touchlocate == 3)
								{
									printf("亲吻\n");
									sexaac = sexaac + 12;
									sexnow = sexnow + 9;
								}
								if (touchlocate == 4)
								{
									printf("顺毛\n");
									if ((girlage <= 15) && (sexaad == 0))
									{
										printf("初识主人\n");
									}
									sexaad = sexaad + 14;
									sexnow = sexnow + 11;
								}
							}
							sexnow = 0;
							printf("它走开了\n");
							system("pause");

							printf("毛:%d\n", petsex);
							if (sextoolhistory == 1)
							{
								printf("使用工具还原上限阈值\n");
								sextop = sextop - 30;
							}
							system("pause");
						}
						if (userchogirl == 2)
						{
							printf("洗澡\n");
							exp = exp + 10;
							srand(time(0));
							bathsex = rand() % 2 + 1;
							if ((bathsex == 2) && (petsex >= 80))
							{
								printf("BATH0\n");
								while (sexnow < sextop)
								{
									printf("1:头\n2:握手\n3:亲吻\n4:顺毛\n");
									scanf("%d", &touchlocate);
									if (touchlocate == 1)
									{
										printf("头\n");
										sexaaa = sexaaa + 5;
										sexnow = sexnow + 4;
									}
									if (touchlocate == 2)
									{
										printf("握手\n");
										sexaab = sexaab + 5;
										sexnow = sexnow + 8;
									}
									if (touchlocate == 3)
									{
										printf("亲吻\n");
										sexaac = sexaac + 12;
										sexnow = sexnow + 9;
									}
									if (touchlocate == 4)
									{
										printf("顺毛\n");
										if ((girlage <= 15) && (sexaad == 0))
										{
											printf("初识主人\n");
										}
										sexaad = sexaad + 14;
										sexnow = sexnow + 11;
									}
								}
								sexnow = 0;
								printf("它走开了\n");
								system("pause");
								exp = exp + 20;
								petsex = petsex + 1.1 * sexup;
							}
							if (bathtool > 0)
							{
								printf("USE BATH TOOL\n");
								petclean = petclean + 40;
							}
							else
							{
								petclean = petclean + 20;
							}
							printf("清洁:%d\n", petclean);
							system("pause");
						}
						if (userchogirl == 3)
						{
							printf(" 商店\n");
							int userbuy = 0;
							exp = exp + 5;
							printf
								("选择物品\n1，顺毛器\n2，面包\n3，沐浴露\n4，玩具\n");
							if (exp > 300)
							{
								printf("1001.调戏店员\n");
							}
							scanf("%d", &userbuy);
							if ((userbuy >= 1) && (userbuy <= 4))
							{
								if (userbuy == 1)
								{
									printf("数量\n");
									scanf("%d", &goodsnumber);
									money = money - 15 * goodsnumber;
									sextool = sextool + goodsnumber;
									printf("顺毛器已购买%d个，现有%d个\n", goodsnumber,
										   sextool);
								}
								if (userbuy == 2)
								{
									printf("数量\n");
									scanf("%d", &goodsnumber);
									money = money - 10 * goodsnumber;
									bread = bread + goodsnumber;
									printf("面包已购买%d个，现有%d个\n", goodsnumber,
										   bread);
								}
								if (userbuy == 3)
								{
									printf("数量\n");
									scanf("%d", &goodsnumber);
									money = money - 15 * goodsnumber;
									bathtool = bathtool + goodsnumber;
									printf("沐浴露已购买%d个，现有%d个\n", goodsnumber,
										   bathtool);
								}
								if (userbuy == 4)
								{
									printf("数量\n");
									scanf("%d", &goodsnumber);
									money = money - 15 * goodsnumber;
									funtool = funtool + goodsnumber;
									printf("玩具已购买%d个，现有%d个\n", goodsnumber,
										   funtool);
								}
							}
							if ((userbuy != 1) && (userbuy != 2) && (userbuy != 3)
								&& (userbuy != 4) && (userbuy != 1001))
							{
								printf("什么也没买\n");
							}
							if (userbuy == 1001)
							{
								while (sexnow < sextop)
								{

								}
								sexnow = 0;
								printf("它走开了\n");
								system("pause");


							}

							if ((userbuy == 1001) && (exp < 300))
							{
								printf("什么也没买\n");
							}
							printf("钱包余额:%d\n", money);
							system("pause");
							system("cls");

						}

						if (userchogirl == 4)
						{
							printf("答题\n");
							money = money + 100;
							printf("钱包余额:%d\n", money);
							system("pause");
						}
						if (userchogirl == 5)
						{
							menuchose = 1;
							ctrldatabase[1] = petheart;
							ctrldatabase[2] = pethungry;
							ctrldatabase[3] = petsex;
							ctrldatabase[4] = petclean;
							ctrldatabase[5] = petmood;
							ctrldatabase[6] = exp;
							ctrldatabase[7] = girlage;
							ctrldatabase[8] = sextool;
							ctrldatabase[9] = bathtool;
							ctrldatabase[10] = funtool;
							ctrldatabase[11] = bread;
							ctrldatabase[12] = money;
							q = 999;
						}
						if (userchogirl == 6)
						{
							printf("治疗中\n");
							Sleep(2000);
							petheart = petheart + 40;
							printf("治疗完成，生命值%d\n", petheart);
							system("pause");
						}
						if (userchogirl == 7)
						{
							printf("厨房\n");
							if (bread <= 0)
							{
								printf("没有面包\n");
							}
							if (bread > 0)
							{
								bread = bread - 1;
								printf("面包.\n");
								pethungry = pethungry + 25;
							}
							printf("饱腹感%d\n", pethungry);
							system("pause");
						}






					}
					if (returnbill == 1)
					{
						printf("还债答题成功\n");
						money = money + 1000;
						system("pause");
					}

				}
				system("cls");
			}
			if (q == 13)
			{
				int hsone, hstwo, hsthr, hsfou, hsfiv, hsx, hsxn = 0, hanshuexit;
				system("cls");
				printf("函数类型\n");
				printf("1.sin mathx \n");
				printf("2.log mathx \n");
				printf("3.mathx² \n");
				printf("4.mathx³ \n");
				printf("5.mathx^-1\n");
				scanf("%d", &hsone);
				printf("横向拉伸\n");
				scanf("%d", &hstwo);
				printf("纵向拉伸\n");
				scanf("%d", &hsthr);
				printf("初相横向正向偏移\n");
				scanf("%d", &hsfou);
				printf("初相纵向正向偏移\n");
				scanf("%d", &hsfiv);
				printf("图像正向滚动长度\n");
				scanf("%d", &hsx);
				hsone = hsone - 1;
				hsx = hsx + 1;
				hstwo = hstwo + 1;
				hsthr = hsthr + 1;
				while (hsxn < hsx)
				{
					system("cls");
					syncpic(hsone, hstwo, hsthr, hsfou, hsfiv);
					Sleep(80);
					hsfou = hsfou + 1;
					hsxn = hsxn + 1;
				}
				printf("Reset(1) or exit(any)?\n");
				scanf("%d", &hanshuexit);
				if (hanshuexit != 1)
				{
					q = 999;
				}
			}
			if (q == 14)
			{

				int musicbase[100], musiclong, musicintlong, nowscanfmusic = 1, musicintorread =
					0, musicinput = 0;
				while (musicinput != 5)
				{
					system("cls");
					printf("MusicPlayer\n");
					printf("手动输入(1)\n读取文件(2)\n");
					scanf("%d", &musicintorread);
					if ((musicintorread == 1) || (musicintorread == 2))
					{
						if (musicintorread == 1)
						{
							printf("输入音符长度\n");
							scanf("%d", &musiclong);
							printf("输入单位音符延时(ms)\n");
							scanf("%d", &musicintlong);
							printf("输入音符\n");
							while (nowscanfmusic <= musiclong)
							{
								printf("第%d个音符\n", nowscanfmusic);
								scanf("%d", &musicbase[nowscanfmusic]);
								nowscanfmusic = nowscanfmusic + 1;
							}
							printf("录入完毕\n");
						}
						if (musicintorread == 2)
						{
							printf("正在读取\n");
							musiclong = wordread(1);
							while (nowscanfmusic <= musiclong)
							{
								musicbase[nowscanfmusic] = wordread(nowscanfmusic + 1);
								nowscanfmusic = nowscanfmusic + 1;
							}
							printf("读取完毕\n");
						}
						musicinput = 5;
					}
					else
					{
						printf("输入错误\n");
					}
					system("pause");
				}


				printf("开始播放\n");
				nowscanfmusic = 1;
				while (nowscanfmusic <= musiclong)
				{
					printf("正在播放第%d个音符\n", nowscanfmusic);
					Beep(musicbase[nowscanfmusic], musicintlong);
					nowscanfmusic = nowscanfmusic + 1;
				}
				printf("播放完毕\n");
				printf("任意键重启，999退出\n");
				int musicboxexit;
				scanf("%d", &musicboxexit);
				if (musicboxexit == 999)
				{
					q = 999;
				}
			}
			if ((q == 8) || (autotest == 2))
			{
				if (debug == 1)
				{
					system("cls");
					printf("Data controller MAX100\n");
					printf("THE 24th SAVER CONTROLED BEEPER W\n");
					printf("THE 25th SAVER CONTROLED BEEPER T\n");
					printf("THE 67th SAVER CONTROLED GAMEPOINT\n");
					printf("THE 51th SAVER CONTROLED GAMERULE\n");
					printf
						("2 to petheart\n3 to pethungry\n4 to petsex\n5 to petclean\n6 to petmood\n7 to exp\n8 to girlage\n9 to sextool\n10 to bathtool\n11 to funtool\n12 to bread\n13 to money\n");
					beginning = 0;
					xxx = 0;
					int inputcir = 0;	// 初始化输入循环变量
					int tableler = 0;
					int locationerr = 0;
					while (inputcir != 1)
					{
						while ((locationerr == 0) && (autotest == 0))
						{
							printf("Input location\n");
							if (autotest == 0)
							{
								scanf("%d", &location);
							}
							if (autotest == 0)
							{
								if ((location >= 1) && (location <= 100))
								{
									locationerr = 1;
								}
								else
								{
									printf("OUT OF SPACE!\n");
									if (autotest == 0)
									{
										system("pause");
									}
									system("cls");
									printf("Data controller MAX100\n");
								}
							}
						}
						location = location - 1;
						printf("Input file\n");
						if (autotest == 0)
						{
							scanf("%d", &file);
						}
						if (autotest == 2)
						{
							Sleep(500);
							ctrldatabase[23] = 500;
							ctrldatabase[24] = 2000;
						}
						if (autotest == 0)
						{
							ctrldatabase[location] = file;	// 分配存储量
						}
						printf("SAVED!\n");
						printf("Input 1 to end input?\n");
						if (autotest == 0)
						{
							scanf("%d", &inputcir);
							system("cls");
							printf("Data controller MAX100\n");
						}
						else
						{
							inputcir = 1;
						}
						if (inputcir != 1)
						{
							locationerr = 0;
						}
					}
					ctrldatabasecir = 0;
					printf("DATA FOLLOWING THESE\n");
					while (ctrldatabasecir < 100)
					{
						schsync = ctrldatabase[ctrldatabasecir];
						ctrldatabasecir = ctrldatabasecir + 1;
						printf("%d ", schsync);
						tableler = ctrldatabasecir % 10;
						if (tableler == 0)
						{
							printf("\n");
						}
					}
					if (autotest == 0)
					{
						system("pause");
					}
					else
					{
						Sleep(2000);
						autotest = 3;
					}
					q = 888;
					system("cls");
				}
				if (debug != 1)
				{

					system("cls");
					printf("Data Container MAX100\n");
					beginningpl = 0;
					yyy = 0;
					int inputcir = 0;	// 初始化输入循环变量
					int tableler = 0;
					int locationerr = 0;
					while (inputcir != 1)
					{
						while ((locationerr == 0) && (autotest == 0))
						{

							printf("Input location\n");
							if (autotest == 0)
							{
								scanf("%d", &location);
							}
							if (autotest == 0)
							{
								if ((location >= 1) && (location <= 100))
								{
									locationerr = 1;
								}
								else
								{
									printf("OUT OF SPACE!\n");
									if (autotest == 0)
									{
										system("pause");
									}
									system("cls");
									printf("Data saver MAX100\n");
								}
							}
						}
						location = location - 1;
						printf("Input file\n");
						if (autotest == 0)
						{
							scanf("%d", &file);
						}
						if (autotest == 2)
						{
							Sleep(500);
							ctrldatabasepl[23] = 500;
							ctrldatabasepl[24] = 2000;
						}
						if (autotest == 0)
						{
							ctrldatabasepl[location] = file;	// 分配存储量
						}
						printf("SAVED!\n");
						printf("Input 1 to end input?\n");
						if (autotest == 0)
						{
							scanf("%d", &inputcir);
							system("cls");
							printf("Data saver MAX100\n");
						}
						else
						{
							inputcir = 1;
						}
						if (inputcir != 1)
						{
							locationerr = 0;
						}
					}
					ctrldatabasecir = 0;
					printf("DATA FOLLOWING THESE\n");
					while (ctrldatabasecir < 100)
					{
						schsync = ctrldatabasepl[ctrldatabasecir];
						ctrldatabasecir = ctrldatabasecir + 1;
						printf("%d ", schsync);
						tableler = ctrldatabasecir % 10;
						if (tableler == 0)
						{
							printf("\n");
						}
					}
					if (autotest == 0)
					{
						system("pause");
					}
					else
					{
						Sleep(2000);
						autotest = 3;
					}
					q = 888;
					system("cls");



				}
			}
			if ((q == 2) || (autotest == 3))
			{
				system("cls");
				while ((q == 2) || (autotest == 3))
				{
					int y, w, h, c, e, r;
					printf("a^b calculator BY NS\n");
					printf("OR 999^999 to file READING DOUBLE\n");
					c = 1;
					w = 0;
					if (autotest == 0)
					{
						scanf("%d%d", &y, &h);
					}
					else
					{
						y = 10;
						h = 2;
					}
					if ((y == 999) && (h == 999))
					{
						int so;
						FILE *mi;
						printf("INPUT SYSTEM TYPE，Windows TO 0，Android TO 1\n");
						scanf("%d", &so);
						if (so == 0)
						{
							mi = fopen("D:\reader\101.txt", "r");
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
							int filesync = 0, syncnow = 1;
							while (syncnow <= 20)
							{
								printf("%d\n", wordread(syncnow));
								syncnow = syncnow + 1;
							}
							printf("DOUBLE RESULT%d\n", wordread(1) * wordread(2));
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
						if (autotest == 3)
						{
							Sleep(1000);
						}
						e = pow(y, h);
						if ((e > 200000000) || (e < -200000000))
						{
							printf("TOO BIG TO CAL \n");
							printf("program is over \n");
							exit;
							exit;
						}
						if (autotest == 3)
						{
							Sleep(1000);
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
							if (autotest == 0)
							{
								scanf("%d", &r);
							}
							else
							{
								r = 0;
								autotest = 4;
								Sleep(1000);
							}
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
			if ((q == 7) || (autotest == 4))
			{
				system("cls");
				printf("递归示例计算程序\n");
				int digui;
				if (autotest == 0)
				{
					scanf("%d", &digui);
				}
				else
				{
					Sleep(700);
					digui = 25;
				}
				digui = fun(digui);
				printf("计算结果%d\n", digui);
				if (autotest == 4)
				{
					Sleep(700);
					autotest = 5;
				}
				if (autotest == 0)
				{
					system("pause");
				}
				q = 999;
				system("cls");
			}
			if ((q == 6) || (autotest == 5))
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
					if (autotest == 0)
					{
						scanf("%d", &andtools);
					}
					else
					{
						andtools = 3;
						autotest = 6;
						Sleep(700);
					}
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
			if ((q == 1) || (autotest == 6))
			{
				while ((q == 1) || (autotest == 6))
				{
					system("cls");
					printf("发声程序\n");
					printf("程序调用WINDOWS BEEP函数\n");
					if (debug == 1)
					{
						printf("DEBUGING\n");
					}
					if ((debug == 1) && (ctrldatabase[23] != 0) && (ctrldatabase[24] != 0) && (autotest != 6))
					{
						printf("Beep as planned\n");
						Beep(ctrldatabase[23], ctrldatabase[24]);
					}
					else
					{
						int bhz, ehz, hztm, scanjump;
						printf("\n");
						printf("\n输入起始频率\n");
						if (autotest == 0)
						{
							scanf("%d", &bhz);
						}
						else
						{
							bhz = 100;
							Sleep(700);
							printf("Done\n");
						}


						printf("输入终止频率\n");

						if (autotest == 0)
						{
							scanf("%d", &ehz);
						}
						else
						{
							ehz = 1000;
							Sleep(700);
							printf("Done\n");
						}
						printf("输入单频播放时间（毫秒）\n");
						if (autotest == 0)
						{
							scanf("%d", &hztm);
						}
						else
						{

							hztm = 300;
							Sleep(700);
							printf("Done\n");
						}
						printf("输入扫描跨度\n");
						if (autotest == 0)
						{
							scanf("%d", &scanjump);
						}
						else
						{
							scanjump = 100;
							Sleep(700);
							printf("Done\n");
						}
						printf("已输入从%dHz到%dHz\n", bhz, ehz);
						printf("单频播放%dms\n", hztm);
						if (hztm <= 5)
						{
							printf("输入单频播放时间过短，有可能无法播放\n");
						}
						if ((bhz >= 20000) || (ehz >= 20000))
						{
							printf
								("发声频率包含超声波，能否发出声波同样取决于当前的音频设备毛能\n");
						}
						if ((bhz <= 20) || (ehz <= 20))
						{
							printf
								("发声频率包含次声波，能否发出声波同样取决于当前的音频设备毛能\n");
							printf
								("注意；次声波可能和人体器官的振动频率相近或相同\n");
							printf
								("响度过大可使心脏出现强烈共振和肺壁受损甚至死亡，请注意\n");
						}
						int addhz, addhzs, addtime;
						addhz = ehz - bhz + 1;
						if (addhz < 0)
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
						if (autotest == 0)
						{
							system("pause");
						}
						else
						{
							Sleep(700);
						}
						while (bhz < ehz)
						{
							printf("正在升调发声%d\n", bhz);
							Beep(bhz, hztm);
							bhz = bhz + scanjump;
						}
						while (ehz < bhz)
						{
							printf("正在降调发声%d\n", bhz);
							Beep(bhz, hztm);
							bhz = bhz - scanjump;
						}
						if (ehz == bhz)
						{
							printf("正在单调发声%d\n", bhz);
							Beep(bhz, hztm);
							bhz = bhz - 1;
						}
					}
					printf
						("运行完毕，输入任意值重启发声程序，结束程序输入0\n");
					int bepover;
					if (autotest == 0)
					{
						scanf("%d", &bepover);
					}
					else
					{
						Sleep(700);
						bepover = 0;
						autotest = 7;
					}
					if (bepover == 0)
					{
						q = 999;
						system("cls");
					}
				}
			}
			if ((q == 3) || (autotest == 7))
			{
				system("cls");
				if (autotest == 7)
				{
					autotest = 8;
				}
				if (autotest == 0)
				{

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


					if (autotest == 0)
					{
						system("pause");
						q = 999;
					}
				}
			}
			if ((q == 4) || (autotest == 8))
			{
				system("cls");
				if (debug == 1)
				{
					printf("程序主界面q为%d\n", q);
				}
				int y, w, k;
				w = 0;
				printf("THIS IS THE ORIGINAL WORK OF SF\n");
				if (autotest == 0)
				{
					scanf("%s%d", &y, &k);
				}
				else
				{
					y = 50;
					k = 50;
					Sleep(700);
				}
				for (; w < k; ++w)
				{
					printf("%d\n", &y);
					printf("%x\n", &y);
					printf("%f\n", &y);

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
				if (autotest == 0)
				{

					scanf("%d", &playexit);
				}
				else
				{
					playexit = 0;
					Sleep(1500);
					autotest = 9;
				}
				if (playexit == 0)
				{
					q = 999;
					system("cls");
				}
			}
			if ((q == 5) || (autotest == 9))
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
							if (autotest == 0)
							{

								scanf("%d%d", &h, &i);
							}
							else
							{
								h = 2;
								i = 1;
								Sleep(700);
							}
							a = h;
							b = i;
							printf("请输入时间跨度，单位:周\n");
							if (autotest == 0)
							{

								scanf("%d", &c);
								Sleep(700);
							}
							t = 0;
							q = 0;
							printf("请输入您当前周数\n");
							if (autotest != 0)
							{
								printf("LOADING...\n");
							}
							if (autotest == 0)
							{
								scanf("%d", &n);
							}
							else
							{
								n = 2;
							}
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
						if (autotest == 0)
						{
							system("pause");
						}
						printf
							("重新计算输入1，结束程序请输入0，继续计算座位请输入任意值\n");
						if (autotest == 0)
						{

							scanf("%d", &cir);
						}
						else
						{
							cir = 0;
							autotest = 10;
							Sleep(700);
						}
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
							if (autotest == 0)
							{

								scanf("%d%d", &aimx, &aimy);
							}
							else
							{
								aimx = 1;
								aimy = 1;
							}
							printf("请输入期望时间段，单位:周\n");
							if (autotest == 0)
							{
								scanf("%d", &aimtime);
							}
							else
							{
								aimtime = 100;
								Sleep(1200);
							}
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
						if (autotest == 0)
						{
							system("pause");
						}
						else
						{
							Sleep(1200);
						}
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
						if (autotest == 0)
						{
							system("pause");
						}
						else
						{
							Sleep(700);
						}
						system("cls");
					}
				}
			}
			if ((q == 10) || (autotest == 10))
			{
				int aaaa, aaab, aaac, aaad, aaae, aaaf, aaag, powcal, logcal;
				srand(time(0));
				aaaa = rand() % 100 + 1;
				aaab = rand() % 100 + 1;
				aaac = rand() % 6 + 1;
				aaae = rand() % 20 + 1;
				aaaf = rand() % 10 + 1;
				aaag = rand() % 5 + 1;
				system("cls");
				printf("SCORE:%d\n", ctrldatabase[66]);
				if (autotest != 10)
				{
					if (aaac == 1)
					{
						printf("%d+%d=\nTips:12138999 to exit\n", aaaa, aaab);
						scanf("%d", &aaad);
						if (aaad == aaaa + aaab)
						{
							ctrldatabase[66] = ctrldatabase[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								q = 999;
							}
							else
							{
								if (ctrldatabase[50] == 1)
								{
									ctrldatabase[66] = ctrldatabase[66] + 1;
									printf("\nRIGHT!\n");
									system("pause");
								}
								else
								{
									printf("WRONG!,ANSWER:%d\n", aaaa + aaab);
									system("pause");
								}
							}
						}
					}
					if (aaac == 2)
					{
						printf("%d-%d=\nTips:12138999 to exit\n", aaaa, aaab);
						scanf("%d", &aaad);
						if (aaad == aaaa - aaab)
						{
							ctrldatabase[66] = ctrldatabase[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								q = 999;
							}
							else
							{
								if (ctrldatabase[50] == 1)
								{
									ctrldatabase[66] = ctrldatabase[66] + 1;
									printf("\nRIGHT!\n");
									system("pause");
								}
								else
								{
									printf("WRONG!,ANSWER:%d\n", aaaa - aaab);
									system("pause");
								}
							}
						}
					}
					if (aaac == 3)
					{
						printf("%dx%d=\nTips:12138999 to exit\n", aaaa, aaab);
						scanf("%d", &aaad);
						if (aaad == aaaa * aaab)
						{
							ctrldatabase[66] = ctrldatabase[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								q = 999;
							}
							else
							{
								if (ctrldatabase[50] == 1)
								{
									ctrldatabase[66] = ctrldatabase[66] + 1;
									printf("\nRIGHT!\n");
									system("pause");
								}
								else
								{

									printf("WRONG!,ANSWER:%d\n", aaaa * aaab);
									system("pause");
								}
							}
						}
					}
					if (aaac == 4)
					{
						printf("%d/%d=(only head section)\nTips:12138999 to exit\n", aaaa, aaag);
						scanf("%d", &aaad);
						if (aaad == aaaa / aaag)
						{
							ctrldatabase[66] = ctrldatabase[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								q = 999;
							}
							else
							{
								if (ctrldatabase[50] == 1)
								{
									ctrldatabase[66] = ctrldatabase[66] + 1;
									printf("\nRIGHT!\n");
									system("pause");
								}
								else
								{

									printf("WRONG!,ANSWER:%d\n", aaaa / aaag);
									system("pause");
								}
							}
						}
					}
					if (aaac == 5)
					{
						printf("%d^%d=\nTips:12138999 to exit\n", aaaf, aaag);
						scanf("%d", &aaad);
						powcal = pow(aaaf, aaag);
						if (aaad == powcal)
						{
							ctrldatabase[66] = ctrldatabase[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								q = 999;
							}
							else
							{
								if (ctrldatabase[50] == 1)
								{
									ctrldatabase[66] = ctrldatabase[66] + 1;
									printf("\nRIGHT!\n");
									system("pause");
								}
								else
								{

									printf("WRONG!,ANSWER:%d\n", powcal);
									system("pause");
								}
							}
						}
					}
					if (aaac == 6)
					{
						printf("lg%d=(only head section)\nTips:12138999 to exit\n", aaae);
						scanf("%d", &aaad);
						logcal = log(aaae);
						if (aaad == logcal)
						{
							ctrldatabase[66] = ctrldatabase[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								q = 999;
							}
							else
							{
								if (ctrldatabase[50] == 1)
								{
									ctrldatabase[66] = ctrldatabase[66] + 1;
									printf("\nRIGHT!\n");
									system("pause");
								}
								else
								{

									printf("WRONG!,ANSWER:%d\n", logcal);
									system("pause");
								}
							}
						}
					}
				}
				if (autotest == 10)
				{
					system("cls");
					printf("Birth these C%dB%dA%d\n", aaac, aaab, aaaa);
					Sleep(1000);
					autotest = 0;
					debug = 0;
					printf("Debug mode off\n");
					printf("Test over\n");
					Sleep(1000);
				}
				if ((aaac > 6) || (aaac < 1))
				{
					printf("Deadly program error C%dB%dAS%d\n", aaac, aaab, aaaa);
					return 0;
				}
			}

		}
	}




}