#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
int ctrldb[200];
int muctrl, menucir, menuerr, debug,ctrldatabasecir, schsync, location, file, password,ctrldatabasepl[100],autotest = 0,xxx = 0, beginning = 0,yyy = 0, beginningpl = 0,debug = 0, regmenucirchk = 0, superuser = 0;

int fun(int x)
{
	if (x > 1)
		return x + fun(x - 1);
	else
		return x;
}

int txtwrite(txtwriter)
{
    #define NTXTREADY 255
	{
		int uui = 1;
		int iwt = 0, maxTXTREAD, TXTREADY, extraier = 0;
		system("mkdir /sdcard/NSFiles/Spcats/NSDData");
		char stxt[NTXTREADY][100], *ptxt, *qtxt = "/sdcard/NSFiles/Spcats/NSDData/CTDATA.db";
		FILE *fptxt;
		if ((fptxt = fopen("/sdcard/NSFiles/Spcats/NSDData/CTDATA.db", "w+")) == NULL)
		{
			printf("���� %s ����", qtxt);
			getch();
		}

		while (extraier < 200)
		{

			while (iwt < 0 && fgets(ctrldb[iwt], 201, fptxt) != NULL)
			{
				ptxt = strchr(ctrldb[iwt], '\n');
				if (ptxt)
					*ptxt = '\0';	/* ����ÿ�����Ļس��� */
				iwt++;
			}
			strcpy(stxt[iwt++], ctrldb);	/* ���뵽��һ�� */

			while (iwt < NTXTREADY && fgets(stxt[iwt], 201, fptxt) != NULL)	/* ������ԭ����
																			 */
			{
				ptxt = strchr(stxt[iwt], '\n');
				if (ptxt)
					*ptxt = '\0';
				iwt++;
			}
			maxTXTREAD = iwt;	/* maxΪ����ʵ�ʵ������� */
			rewind(fptxt);

			for (iwt = 0; iwt < maxTXTREAD; iwt++)
			{
				fprintf(fptxt, "%d\n", ctrldb[iwt]);	/* ������ļ�a.txt��
														 */
			}
			extraier = extraier + 1;
		}
		{
			printf("���ݿ⵼���ɹ�\n");
		}
		fclose(fptxt);
		getch();
	}
}

int timesigner(int tsgninput)
{
	int timenow, b, year, month, day, hour, minute, second;
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
	if (wordread(sewhat) == 404)
	{
		return 404;
	}
	else
	{
		while (sewhatdata <= 200)
		{
			ctrldb[sewhatdata - 1] = wordread(sewhatdata);
			sewhatdata = sewhatdata + 1;
		}
		return 999;
	}
}

int wordread(whichLine)
{
	whichLine = whichLine - 1;
	FILE *datafile;
	int intlikenum;
	int currentLine = 0, foundpotsen = 0;
	char strLine[1024];
	datafile = fopen("/sdcard/NSFiles/Spcats/NSDData/CTDATA.db", "r");
	if (datafile == NULL)
	{
		return 404;
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

int senread(whichLinesen)
{
	whichLinesen = whichLinesen - 1;
	FILE *datafilesen;
	int intlikenumsen;
	int currentLinesen = 0, foundpotsensen = 0;
	char strLinesen[1024];
	if ((datafilesen = fopen("/sdcard/NSFiles/Spcats/NSDlib/SENTENCES.db", "r")) == NULL)
	{
		if (whichLinesen != 0)
		{
			printf("ȱ�ٶԻ��⵼�µ�%d�������޷���ʾ\n", whichLinesen + 1);
		}
		return 404;
	}
	while ((foundpotsensen == 0) && (whichLinesen != 0))
	{

		if (currentLinesen == whichLinesen)
		{
			fgets(strLinesen, 1024, datafilesen);
			foundpotsensen = 1;
			printf("%s", strLinesen);
		}
		fgets(strLinesen, 1024, datafilesen);
		currentLinesen = currentLinesen + 1;
	}
	fclose(datafilesen);
	Sleep(500);
	return 999;
}

int dbhelper(helpze)
{
	int helpzexxx = 0;
	helpzexxx = ctrldb[helpze];
	return helpzexxx;
}

int syncpic(hankind, hanx, hany, hanpx, hanpy)
{
	int xscan = 0, atcounter = 0, fxfixer = 0, fxsmaller;
	double pic[60], mathy, mathx;
	while (xscan < 60)
	{
		mathx = hanx * (0.2 * xscan - 6 + hanpx);
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
		if (hankind == 5)
		{
			mathy = dbhelper(mathx);
		}
		pic[xscan] = 3 * hany * mathy + 16 + hanpy;
		xscan = xscan + 1;
	}
	xscan = 0;
	int fx;
    mathx = 0, mathy = 30;
	while (mathy >= 0)
	{
		fx = pic[(int)mathx];
		if (fx == 16)
		{
			atcounter = atcounter + 1;
		}
		if (mathy == fx)
		{
			printf("@");
		}
		if (mathy != fx)
		{
			printf(".");
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
	atcounter = atcounter / 30;
	if (atcounter > 55)
	{
		printf("�հ�ͼ����Ӧ����\n");
		fxfixer = 404;
	}
	if ((atcounter <= 55) && (fxfixer == 404))
	{
		printf("�հ�ͼ����Ӧ�ر�\n");
		fxfixer = 999;
	}
	if (fxfixer == 404)
	{
		printf("ͼ���Զ���������������%d��λ��...\n", hany);
		Sleep(500);
		system("cls");
		syncpic(hankind, hanx, hany + 1, hanpx, hanpy);
	}
}


int bytime(gailv)
{
	int bytimeresult;
	srand(time(0));
	bytimeresult = rand() % gailv + 1;
	return bytimeresult;
}

int senreader(senreaderline)
{
    int senerrchk;
    senerrchk = senread(senreaderline);
    if (senreaderline!=1)
    {
    printf ("\n");
    }
    return senerrchk;
}

int name(xname)
{
	if (xname == 1)
	{
		senreader(123);
	}
	if (xname == 2)
	{
		senreader(124);
	}
	if (xname == 3)
	{
		senreader(125);
	}
}


int gctiver(type)
{
	int scanlocate, dohigh,activelogger=0, dohighcho, highactivemode = 0;
	if (type != 8)
	{
		senreader(90 + type);
		senreader(ctrldb[7] + 34);
		senreader(3);
	}
	if (type == 8)
	{
		senreader(55);
        senreader(37);
	}
	while (ctrldb[119] < ctrldb[121])
	{
		if (scanlocate !=4)
		{
		if (highactivemode != 1)
		{
			senreader(111);
		}
		if (highactivemode == 1)
		{
			senreader(9);
		}

		scanf("%d", &scanlocate);
		}
		if (scanlocate == 1)
		{
			senreader(6);
			Sleep(1000);
			ctrldb[115] = ctrldb[115] + 5;
			ctrldb[3] = ctrldb[3]+18;
		}
		if (scanlocate == 2)
		{
			senreader(5);
			Sleep(1000);
			ctrldb[116] = ctrldb[116] + 5;
			ctrldb[119] = ctrldb[119] + 9;
			ctrldb[3] = ctrldb[3]+22;
		}
		if (scanlocate == 3)
		{
			senreader(4);
			Sleep(1000);
			ctrldb[118] = ctrldb[118] + 12;
			ctrldb[3] = ctrldb[3]+28;
		}
		if (scanlocate == 4)
		{
			srand(time(0));
			senreader(10*ctrldb[119]/ctrldb[121]+99);
		if (highactivemode==1)
		{
			senreader(34);
			Sleep(1000);
			}
		if (highactivemode!=1)
		{
			senreader(122);
			Sleep(1000);
			}
			if(scanlocate!=0)
			{
			printf("Matter%d\n",100*ctrldb[119]/ctrldb[121]);
			}
			scanf("%d", &dohighcho);


			if (dohighcho == 1)
			{
				if ((ctrldb[7] <= 15) && (ctrldb[120] == 0))
				{
					senreader(21);
					Sleep(1000);
					activelogger=activelogger+1;
			ctrldb[3] = ctrldb[3]+8;
				}
				senreader(ctrldb[7] + 44);
				Sleep(1000);
				ctrldb[120] = ctrldb[120] + 14;
				activelogger=activelogger+1;
				ctrldb[119] = ctrldb[119] + 11;
			ctrldb[3] = ctrldb[3]+8;
			}
			if (dohighcho == 2)
			{
				highactivemode = 1;
				if ((ctrldb[7] <= 15) && (ctrldb[120] == 0))
				{
					senreader(35);
					Sleep(1000);
					activelogger=activelogger+1;
			ctrldb[3] = ctrldb[3]-18;
					highactivemode = 0;
				}
				senreader(rand()%8+66);
				activelogger=activelogger+1;
				senreader(36);
				Sleep(1000);
				ctrldb[120] = ctrldb[120] + 24;
				ctrldb[119] = ctrldb[119] + 19;
				ctrldb[6]=ctrldb[6]+23;
			ctrldb[3] = ctrldb[3]+32;
			}
			if((dohighcho==3)&&(highactivemode==0))
			{
			    scanlocate=0;;
			    senreader(121);
			   	Sleep(1000);
			}
		}
		if ((scanlocate == 5)&& (highactivemode == 0))
		{
		    if (activelogger!=0)
		    {
			senreader(75);
			Sleep(1000);
			}
			ctrldb[119] = 1000;
		}
	}
		    if (activelogger!=0)
		    {
		if (ctrldb[119] != 1000)
		{
			senreader(76);
			Sleep(1000);
		}
			}
	if ((scanlocate==5) && (highactivemode == 0))
	{
		if (ctrldb[119] != 1000)
		{
			senreader(75);
			Sleep(1000);
		}
	}
	scanlocate=0;
}
void one()
{
				while ((muctrl == 1) || (autotest == 6))
				{
					system("cls");
					printf("��������\n");
					printf("�������WINDOWS BEEP����\n");
					if (debug == 1)
					{
						printf("DEBUGING\n");
					}
					if ((debug == 1) && (ctrldb[23] != 0) && (ctrldb[24] != 0) && (autotest != 6))
					{
						printf("Beep as planned\n");
						Beep(ctrldb[23], ctrldb[24]);
					}
					else
					{
						int bhz, ehz, hztm, scanjump;
						printf("\n");
						printf("\n������ʼƵ��\n");
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


						printf("������ֹƵ��\n");

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
						printf("���뵥Ƶ����ʱ�䣨���룩\n");
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
						printf("����ɨ����\n");
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
						printf("�������%dHz��%dHz\n", bhz, ehz);
						printf("��Ƶ����%dms\n", hztm);
						if (hztm <= 5)
						{
							printf("���뵥Ƶ����ʱ����̣��п����޷�����\n");
						}
						if ((bhz >= 20000) || (ehz >= 20000))
						{
							printf
								("����Ƶ�ʰ������������ܷ񷢳�����ͬ��ȡ���ڵ�ǰ����Ƶ�豸ë��\n");
						}
						if ((bhz <= 20) || (ehz <= 20))
						{
							printf
								("����Ƶ�ʰ������������ܷ񷢳�����ͬ��ȡ���ڵ�ǰ����Ƶ�豸ë��\n");
							printf
								("ע�⣻���������ܺ��������ٵ���Ƶ���������ͬ\n");
							printf
								("��ȹ����ʹ�������ǿ�ҹ���ͷα�����������������ע��\n");
						}
						int addhz, addhzs, addtime;
						addhz = ehz - bhz + 1;
						if (addhz < 0)
						{
							printf("�ѽ��и�ֵ����\n");
							addhzs = 0 - addhz;
						}
						else
						{
							addhzs = addhz;
						}
						addtime = addhzs * hztm;
						addtime = addtime / 1000;
						addtime = addtime / scanjump;
						printf("����״̬����ʱ��%ds\n", addtime);
						printf("���������ʼ����\n");
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
							printf("������������%d\n", bhz);
							Beep(bhz, hztm);
							bhz = bhz + scanjump;
						}
						while (ehz < bhz)
						{
							printf("���ڽ�������%d\n", bhz);
							Beep(bhz, hztm);
							bhz = bhz - scanjump;
						}
						if (ehz == bhz)
						{
							printf("���ڵ�������%d\n", bhz);
							Beep(bhz, hztm);
							bhz = bhz - 1;
						}
					}
					printf
						("������ϣ���������ֵ�����������򣬽�����������0\n");
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
						muctrl = 999;
						system("cls");
					}
				}
			}

void two()
{
				system("cls");
				while ((muctrl == 2) || (autotest == 3))
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
						printf("INPUT SYSTEM TYPE��Windows TO 0��Android TO 1\n");
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
								printf("CAN NOT READ THE FILE��\n");
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
							printf("�������\n");
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
							printf("%d��%d�η�Ϊ%d\n", y, w, c);
							w = w + 1;
						}
						printf("computational completion\n");
						printf("if you want to end this program ");
						printf("just input ��0�� \n");
						printf("if you want to try again,please input ��1��\n");
						printf("����shrink\n");
						printf("˧�������̼�������\n");
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
								muctrl = 999;
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

void three()
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
						printf("����������muctrlΪ%d\n", muctrl);
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
							muctrl = 999;
							printf("exit to menu successfully\n");
							system("cls");
						}
						switch (j)
						{
						case 1:
							printf("MONDAY ����һ\n");
							scanf("%d", &f);
							break;
						case 2:
							printf("TUESDAY ���ڶ�\n");
							scanf("%d", &f);
							break;
						case 3:
							printf("WEDNESDAY ������\n");
							scanf("%d", &f);
							break;
						case 4:
							printf("THURSDAY ������\n");
							scanf("%d", &f);
							break;
						case 5:
							printf("FRIDAY ������\n");
							scanf("%d", &f);
							break;
						case 6:
							printf("SATURDAY ������\n");
							scanf("%d", &f);
							break;
						case 7:
							printf("SUNDAY ������\n");
							scanf("%d", &f);
							break;
						}
					}


					if (autotest == 0)
					{
						system("pause");
						muctrl = 999;
					}
				}
			}

void four()
{
				system("cls");
				if (debug == 1)
				{
					printf("����������muctrlΪ%d\n", muctrl);
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
				printf("˧�������̼�������\n");
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
					muctrl = 999;
					system("cls");
				}
			}

void five()
{
				system("cls");
				if (debug == 1)
				{
					printf("�����ʼ������muctrlΪ%d\n", muctrl);
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
								printf("����������muctrlΪ%d��cirΪ%d\n", muctrl, cir);
							}

							printf("�����뵱ǰ����������\n");
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
							printf("������ʱ���ȣ���λ:��\n");
							if (autotest == 0)
							{

								scanf("%d", &c);
								Sleep(700);
							}
							t = 0;
							muctrl = 0;
							printf("����������ǰ����\n");
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
								printf("�������\n");
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
							printf("������λ������(%d��4)\n", a);
						}
						else
						{
							muctrl = 1;
							while (muctrl <= c)
							{
								b = b + a;
								a = a + 1;
								muctrl = muctrl + 1;
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
							printf("������λ����Ϊ(%d��%d)\n", a, b);
						}
						if (autotest == 0)
						{
							system("pause");
						}
						printf
							("���¼�������1����������������0������������λ����������ֵ\n");
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
						printf("��������ֹ\n");
						system("cls");
						if (debug == 1)
						{
							printf("δ�˳�ʱmuctrlΪ%d��cirΪ%d\n", muctrl, cir);
						}
						muctrl = 999;
						cir = 999;
						muctrl = 999;
						seatcir = 999;
						if (debug == 1)
						{
							printf("�˳�ʱmuctrlΪ%d��cirΪ%d\n", muctrl, cir);
						}

					}
					else
					{
						int targeterr;
						targeterr = 1;
						while (targeterr == 1)
						{
							printf("��������������������\n");
							if (autotest == 0)
							{

								scanf("%d%d", &aimx, &aimy);
							}
							else
							{
								aimx = 1;
								aimy = 1;
							}
							printf("����������ʱ��Σ���λ:��\n");
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
								printf("�������\n");
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
									printf("%d�ܺ�ɴ�Ŀ��λ��\n", sss + 1);
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
									printf("%d�ܺ�ɴ�Ŀ��λ��\n", sss + 1);
									ungetrtn = 1;
								}
								sss = sss + 1;
							}
						}
						if (ungetrtn == 0)
						{
							printf("����ָ����Χ��û�л�����������λ\n");
						}
						printf("�������������λ����plus\n");
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
						printf("���߱�д�У���Ǹ\n");
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

void six()
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
						muctrl = 999;
						system("cls");
						toolserr = 0;
					}
					if (toolserr == 1)
					{
						printf("retry\n");
					}
				}
			}

void seven()
{
				system("cls");
				printf("�ݹ�ʾ���������\n");
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
				printf("������%d\n", digui);
				if (autotest == 4)
				{
					Sleep(700);
					autotest = 5;
				}
				if (autotest == 0)
				{
					system("pause");
				}
				muctrl = 999;
				system("cls");
			}

void eight()
{
				if (debug == 1)
				{
					system("cls");
					printf("�������ݿ������ ��λ100λ\n");
					beginning = 0;
					xxx = 0;
					int inputcir = 0;	// ��ʼ������ѭ������
					int tableler = 0;
					int locationerr = 0;
					while (inputcir != 1)
					{
						while ((locationerr == 0) && (autotest == 0))
						{
							printf("����ֵλ\n");
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
									printf("����ֵ��!\n");
									if (autotest == 0)
									{
										system("pause");
									}
									system("cls");
									printf("�������ݿ������ ��λ100λ\n");
								}
							}
						}
						location = location - 1;
						printf("�븳ֵ\n");
						if (autotest == 0)
						{
							scanf("%d", &file);
						}
						if (autotest == 2)
						{
							Sleep(500);
							ctrldb[23] = 500;
							ctrldb[24] = 2000;
						}
						if (autotest == 0)
						{
							ctrldb[location] = file;	// ����洢��
						}
						printf("�ѱ���!\n");
						printf("����1�˳���ǰ��������ֵ������ֵ\n");
						if (autotest == 0)
						{
							scanf("%d", &inputcir);
							system("cls");
							printf("�������ݿ������ ��λ100λ\n");
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
					printf("���ݿ���Ϣ����\n");
					while (ctrldatabasecir < 100)
					{
						schsync = ctrldb[ctrldatabasecir];
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
					muctrl = 888;
					system("cls");
				}
				if (debug != 1)
				{

					system("cls");
					printf("�Զ����������ɲ֣���λ100\n");
					beginningpl = 0;
					yyy = 0;
					int inputcir = 0;	// ��ʼ������ѭ������
					int tableler = 0;
					int locationerr = 0;
					while (inputcir != 1)
					{
						while ((locationerr == 0) && (autotest == 0))
						{

							printf("������λ\n");
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
									printf("��������!\n");
									if (autotest == 0)
									{
										system("pause");
									}
									system("cls");
									printf("�Զ����������ɲ֣���λ100\n");
								}
							}
						}
						location = location - 1;
						printf("����ֵ\n");
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
							ctrldatabasepl[location] = file;	// ����洢��
						}
						printf("�ѱ���!\n");
						printf("����1�˳���ǰ��������ֵ������ֵ\n");
						if (autotest == 0)
						{
							scanf("%d", &inputcir);
							system("cls");
							printf("�Զ����������ɲ֣���λ100\n");
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
					printf("��������\n");
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
					muctrl = 888;
					system("cls");



				}
			}

void nine()
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
					printf("����1���뵹��ʱ��2����ʱ�����\n");
					printf("ע�⣬����ʱ����Ӻ��ܷ���ĸ�˵�\n");
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
						muctrl = 999;
						timemenucir = 1;
						system("cls");
					}
					printf("������......\n");
					Sleep(300);
					system("cls");
					if (ambcho == 1)
					{
						printf("���뵹��ʱ����\n");
						if (autotest == 0)
						{
							scanf("%d", &goaltime);
						}
						else
						{
							goaltime = 3;
						}
						printf("����ʱ������(0 to choose)\n");
						if (autotest == 0)
						{
							scanf("%d", &beepcho);
						}
						else
						{
							beepcho = 0;
						}
						printf("������\n");
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
									printf("ʱ�䵽\n");
									if (beepcho == 0)
									{
										if ((debug == 1) && (ctrldb[23] != 0) && (ctrldb[24] != 0))
										{
											Beep(ctrldb[23], ctrldb[24]);
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
									printf("����0�˳�������ֵ����ʱ����� ?\n");
									printf
										("ע�⣬����ʱ����Ӻ��ܷ���ĸ�˵�\n");
									ambcho = 2;
									if (debug == 1)
									{
										printf("�ӳ�����ֵ����\n");
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
										printf("muctrl:%d\n", muctrl);
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
										printf("α���ʱ�����:%d\n", timemach);
									}
									if (ambcho == 1)
									{
										lasttime = goaltime - (timenow - timeold);
										printf("ʣ��ʱ������:%d\n", lasttime);
									}
								}
								checker = second;
							}
						}
					}
				}
			}

void ten()
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
				printf("SCORE:%d\n", ctrldb[66]);
				if (autotest != 10)
				{
					if (aaac == 1)
					{
						printf("%d+%d=\nTips:12138999 to exit\n", aaaa, aaab);
						scanf("%d", &aaad);
						if (aaad == aaaa + aaab)
						{
							ctrldb[66] = ctrldb[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								muctrl = 999;
							}
							else
							{
								if (ctrldb[50] == 1)
								{
									ctrldb[66] = ctrldb[66] + 1;
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
							ctrldb[66] = ctrldb[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								muctrl = 999;
							}
							else
							{
								if (ctrldb[50] == 1)
								{
									ctrldb[66] = ctrldb[66] + 1;
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
							ctrldb[66] = ctrldb[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								muctrl = 999;
							}
							else
							{
								if (ctrldb[50] == 1)
								{
									ctrldb[66] = ctrldb[66] + 1;
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
							ctrldb[66] = ctrldb[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								muctrl = 999;
							}
							else
							{
								if (ctrldb[50] == 1)
								{
									ctrldb[66] = ctrldb[66] + 1;
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
							ctrldb[66] = ctrldb[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								muctrl = 999;
							}
							else
							{
								if (ctrldb[50] == 1)
								{
									ctrldb[66] = ctrldb[66] + 1;
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
							ctrldb[66] = ctrldb[66] + 1;
							printf("\nRIGHT!\n");
							system("pause");
						}
						else
						{
							if (aaad == 12138999)
							{
								muctrl = 999;
							}
							else
							{
								if (ctrldb[50] == 1)
								{
									ctrldb[66] = ctrldb[66] + 1;
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
					printf("Deadly program error said C%dB%dAS%d\n", aaac, aaab, aaaa);
					return 0;
				}
			}

void twelve()
{
				system("cls");
				int freecho,userchogrpet,userbuy;
				if (ctrldb[6] == 0)
				{
					ctrldb[1] = 100;
					ctrldb[5] = 100;
					ctrldb[3] = 55;
					ctrldb[2] = 100;
					ctrldb[4] = 100;
					ctrldb[101] = 0;
					ctrldb[102] = 0;
					ctrldb[103] = 0;
					ctrldb[104] = 0;
					ctrldb[105] = 0;
					ctrldb[12] = 100;
					ctrldb[106] = 0;
					ctrldb[11] = 0;
					ctrldb[8] = 0;
					ctrldb[107] = 0;
					ctrldb[9] = 0;
					ctrldb[10] = 0;
					ctrldb[108] = 0;
					ctrldb[109] = 0;
					ctrldb[110] = 0;
					ctrldb[111] = 0;
					ctrldb[112] = 0;
					ctrldb[113] = 0;
					ctrldb[114] = 0;
					ctrldb[115] = 0;
					ctrldb[116] = 0;
					ctrldb[117] = 0;
					ctrldb[118] = 0;
					ctrldb[119] = 0;
					ctrldb[120] = 0;
					ctrldb[7] = rand() % 5 + 14;
					ctrldb[107] = rand() % 3 + 1;
                    senreader(126);
					name(ctrldb[107]);


					senreader(33);
					if (ctrldb[107] == 1)
					{
						ctrldb[110] = 10;
						ctrldb[111] = 15;
						ctrldb[112] = 20;
						ctrldb[113] = 8;
						ctrldb[121] = 30;
					}
					if (ctrldb[107] == 2)
					{
						ctrldb[110] = 15;
						ctrldb[111] = 8;
						ctrldb[112] = 12;
						ctrldb[113] = 7;
						ctrldb[121] = 20;
					}
					if (ctrldb[107] == 3)
					{
						ctrldb[111] = 30;
						ctrldb[112] = 19;
						ctrldb[113] = 15;
						ctrldb[110] = 29;
						ctrldb[121] = 50;
					}
					printf("\n");
					ctrldb[6] = ctrldb[6] + 1;
				}
				system("pause");
				while ((ctrldb[6] > 0) && (muctrl == 12))
				{
					system("cls");
					if ((ctrldb[6] > 200) && (ctrldb[3] < 0))
					{
						ctrldb[3] = 0;
						senreader(2);
						Sleep(1500);
						gctiver(1);
						ctrldb[3] = ctrldb[3] + 55;
						senreader(10);
						ctrldb[119] = 0;
						system("pause");
						ctrldb[1] = ctrldb[1] - ctrldb[110] * (16 - ctrldb[7]);
					}
					if ((ctrldb[6] > 100) && (ctrldb[109] == 0))
					{
				senreader(116);
						ctrldb[109] = ctrldb[109] + 1;
						ctrldb[121] = ctrldb[121] + 20;
						system("pause");
					}
					if ((ctrldb[6] > 500) && (ctrldb[109] == 1))
					{
				senreader(117);
						ctrldb[109] = ctrldb[109] + 1;
						ctrldb[121] = ctrldb[121] + 20;
						system("pause");
					}
					if ((ctrldb[6] > 800) && (ctrldb[109] == 2))
					{
				senreader(118);
						ctrldb[109] = ctrldb[109] + 1;
						ctrldb[121] = ctrldb[121] + 50;
						system("pause");
					}
					if (ctrldb[2] <= 0)
					{
						ctrldb[2] = 0;
						senreader(11);
						ctrldb[1] = ctrldb[1] - ctrldb[110];
					}
					if (ctrldb[4] < 0)
					{
						senreader(12);
						ctrldb[1] = ctrldb[1] - 0.5 * ctrldb[110];
					}
					if (ctrldb[5] < 0)
					{
						senreader(13);
						ctrldb[1] = ctrldb[1] - 0.8 * ctrldb[110];
					}

					freecho = rand() % 8 + 1;
					if (freecho == 1)
					{
						senreader(14);
						ctrldb[1] = ctrldb[1] - ctrldb[110];
					}
					if ((freecho == 2) && (ctrldb[6] > 50))
					{
						senreader(15);
						ctrldb[4] = ctrldb[4] - 10;
						ctrldb[5] = ctrldb[5] + ctrldb[113];
						if (ctrldb[8] >= 1)
						{
							ctrldb[3] = ctrldb[3] + 0.6 * ctrldb[112];
							ctrldb[8] = ctrldb[8] - 1;
						}
					}
					if (freecho == 3)
					{
						senreader(16);
						ctrldb[3] = ctrldb[3] - 1.5 * ctrldb[111];
					}
					if (freecho == 4)
					{
						senreader(17);
						ctrldb[1] = ctrldb[1] - ctrldb[110];
					}
					if (freecho == 5)
					{
						senreader(18);
						ctrldb[5] = ctrldb[5] - ctrldb[113];
					}
					if (freecho == 6)
					{
						senreader(19);
						ctrldb[1] = ctrldb[1] - 0.2 * ctrldb[110];
						ctrldb[5] = ctrldb[5] - 0.6 * ctrldb[113];
						ctrldb[3] = ctrldb[3] - 0.4 * ctrldb[111];
					}
					if (freecho == 7)
					{
						printf("��\n");
						ctrldb[2] = ctrldb[2] - 10;
					}
					if ((ctrldb[6] > 600) && (ctrldb[8] > 1) && (freecho == 8))
					{
						senreader(20);
						gctiver(2);
						ctrldb[119] = 0;
						senreader(10);
						ctrldb[3] = ctrldb[3] + 0.85 * ctrldb[112];
						system("pause");
					}
					if (ctrldb[12] >= 0)
					{
						ctrldb[108] = 0;
					}
					if (ctrldb[12] < 0)
					{
						printf("����Ƿծ%dԪ\n", 0 - ctrldb[12]);
						senreader(22);
						ctrldb[108] = 1;
					}
					if (ctrldb[3] < 50)
					{
						printf("״̬:����\n");
						senreader(77);
					}
					if (ctrldb[2] < 50)
					{
						printf("״̬:����\n");
						senreader(78);
					}
					if (ctrldb[4] < 50)
					{
						printf("״̬:��\n");
						senreader(79);
					}
					if (ctrldb[5] < 50)
					{
						printf("״̬:����\n");
						senreader(80);
					}
					if (ctrldb[1] < 50)
					{
						printf("״̬:����\n");
						senreader(81);
					}
					if (ctrldb[1] < 0)
					{
						ctrldb[6] = 0;
						senreader(115);
						system("pause");
						system("cls");
					}
					if ((ctrldb[1] > 0) && (ctrldb[108] == 0))
					{
						srand(time(0));
						ctrldb[102] = rand() % 6 + 1;
						if ((ctrldb[102] == 1)&&(ctrldb[6]>1600)&&(ctrldb[3]>300))
						{
							senreader(23);
							ctrldb[6] = ctrldb[6] + 12;
							srand(time(0));
							ctrldb[103] = rand() % 15 + 10;
							ctrldb[3] = ctrldb[3] + ctrldb[103] * 0.05 * ctrldb[112];
							if (ctrldb[103] <= 12)
							{
								senreader(44);
							}
							if ((ctrldb[103] > 12) && (ctrldb[103] <= 20))
							{
								senreader(65);
							}
							if ((ctrldb[103] > 20) && (ctrldb[103] <= 25))
							{
								senreader(46);
							}
							system("pause");
						}
						if (ctrldb[102] == 2)
						{
							senreader(24);
							int userbuy = 0;
							ctrldb[6] = ctrldb[6] + 4;
							printf
								("ѡ����Ʒ\n1��DUREX\n2���ױ�\n3����ԡ¶\n4��������\n");
							scanf("%d", &userbuy);
							if ((userbuy >= 1) && (userbuy <= 4))
							{
								if (userbuy == 1)
								{
									printf("����\n");
									scanf("%d", &ctrldb[114]);
									ctrldb[12] = ctrldb[12] - 15 * ctrldb[114];
									ctrldb[8] = ctrldb[8] + ctrldb[114];
									printf("DUREX�ѹ���%d��������%d��\n", ctrldb[114],
										   ctrldb[8]);
								}
								if (userbuy == 2)
								{
									printf("����\n");
									scanf("%d", &ctrldb[114]);
									ctrldb[12] = ctrldb[12] - 10 * ctrldb[114];
									ctrldb[11] = ctrldb[11] + ctrldb[114];
									printf("�ױ��ѹ���%d��������%d��\n", ctrldb[114],
										   ctrldb[11]);
								}
								if (userbuy == 3)
								{
									printf("����\n");
									scanf("%d", &ctrldb[114]);
									ctrldb[12] = ctrldb[12] - 15 * ctrldb[114];
									ctrldb[9] = ctrldb[9] + ctrldb[114];
									printf("��ԡ¶�ѹ���%d��������%d��\n", ctrldb[114],
										   ctrldb[9]);
								}
								if (userbuy == 4)
								{
									printf("����\n");
									scanf("%d", &ctrldb[114]);
									ctrldb[12] = ctrldb[12] - 15 * ctrldb[114];
									ctrldb[10] = ctrldb[10] + ctrldb[114];
									printf("�������ѹ���%d��������%d��\n", ctrldb[114],
										   ctrldb[10]);
								}
							}
							else
							{
								printf("ʲôҲû��\n");
							}
							printf("���ʲ�:%d\n", ctrldb[12]);
							system("pause");
							system("cls");
						}
						if (ctrldb[102] == 3)
						{
							senreader(7);
							ctrldb[6] = ctrldb[6] + 12;
							srand(time(0));
							ctrldb[104] = rand() % 2 + 1;
							if ((ctrldb[104] == 2) && (ctrldb[3] >= 80) && (ctrldb[6] > 400)
								&& (ctrldb[8] > 1))
							{
								senreader(29);
								gctiver(3);
								ctrldb[119] = 0;
								senreader(10);
								system("pause");
								ctrldb[6] = ctrldb[6] + 20;
								ctrldb[3] = ctrldb[3] + 1.1 * ctrldb[112];
							}
							ctrldb[4] = ctrldb[4] + 14;
							system("pause");
						}
						if (ctrldb[102] == 4)
						{
							senreader(25);
							ctrldb[2] = ctrldb[2] + 30;
							ctrldb[12] = ctrldb[12] - 20;
							ctrldb[6] = ctrldb[6] + 8;
							printf("���ʲ�:%d\n", ctrldb[12]);
							system("pause");
						}
						if (ctrldb[102] == 5)
						{
							senreader(26);
                            senreader(8);
							ctrldb[6] = ctrldb[6] + 11;
							system("pause");
							srand(time(0));
							ctrldb[106] = rand() % 2 + 1;
							if ((ctrldb[106] == 2) && (ctrldb[3] >= 150) && (ctrldb[8] >= 1))
							{
								senreader(30);
gctiver(4);
								ctrldb[119] = 0;
								senreader(10);
								system("pause");
								ctrldb[6] = ctrldb[6] + 20;
								ctrldb[3] = ctrldb[3] + 0.95 * ctrldb[112];
								ctrldb[8] = ctrldb[8] - 1;
							}
						}
						if (ctrldb[102] == 6)
						{
							senreader(27);
							ctrldb[6] = ctrldb[6] + 7;
							srand(time(0));
							ctrldb[105] = rand() % 2 + 1;
							if ((ctrldb[6] > 400) && (ctrldb[105] == 2) && (ctrldb[3] >= 80)
								&& (ctrldb[8] > 1))
							{
								senreader(32);
								gctiver(5);
								ctrldb[119] = 0;
								senreader(10);
								system("pause");
								ctrldb[6] = ctrldb[6] + 10;
								ctrldb[3] = ctrldb[3] + ctrldb[112];
							}
							system("pause");
						}
						printf("����%d   ����%d   ������%d   ��%d\n���%d   ����%d   ����ֵ%d   ���ʲ�%d\n", ctrldb[7], ctrldb[1], ctrldb[2], ctrldb[3], ctrldb[4], ctrldb[5], ctrldb[6], ctrldb[12]);
						if (ctrldb[6]>	300)
						{
						    printf("��ͷ���ж�%d   �������ж�%d   �����ж�%d\n�������ж�%d   �߳�����%d\n",ctrldb[115], ctrldb[116], ctrldb[118],ctrldb[120], ctrldb[121]);
						}
						printf
							("1 ȥ����\n2 ȥԡ��\n3 ȥ����\n4 ȥ����\n5 �������˵�\n6 ȥҽԺ\n7 ȥ����\n�������������ѡ��\n");
						scanf("%d", &userchogrpet);
						if (userchogrpet == 1)
						{
							if ((ctrldb[6] > 300) && (ctrldb[8] > 0))
							{
senreader(120);
								ctrldb[3] = ctrldb[3] + 2 * ctrldb[112];
								ctrldb[121] = ctrldb[121] + 30;
								ctrldb[117] = 1;
								ctrldb[8] = ctrldb[8] - 1;
							}
							if ((ctrldb[6] > 300) && (ctrldb[8] == 0))
							{
								ctrldb[3] = ctrldb[3] + 0.7 * ctrldb[112];
							}
							if (ctrldb[6] > 300)
							{
								gctiver(6);
								ctrldb[119] = 0;
								senreader(10);
							}
							if (ctrldb[6] <= 300)
							{
								senreader(112);
								ctrldb[1] = ctrldb[1] + 10;
ctrldb[6]=ctrldb[6]+40;
							}
							system("pause");
							if (ctrldb[117] == 1)
							{
								senreader(31);
								ctrldb[121] = ctrldb[121] - 30;
							}
							system("pause");
						}
						if (userchogrpet == 2)
						{
							senreader(43);
							ctrldb[6] = ctrldb[6] + 10;
							srand(time(0));
							ctrldb[104] = rand() % 2 + 1;
							if ((ctrldb[104] == 2) && (ctrldb[3] >= 80) && (ctrldb[6] > 600)
								&& (ctrldb[8] > 1))
							{
								senreader(29);
								gctiver(7);
								ctrldb[119] = 0;
								senreader(10);
								system("pause");
								ctrldb[6] = ctrldb[6] + 20;
								ctrldb[3] = ctrldb[3] + 1.1 * ctrldb[112];
							}
							if (ctrldb[9] > 0)
							{
								senreader(119);
								ctrldb[4] = ctrldb[4] + 40;
							}
							else
							{
								ctrldb[4] = ctrldb[4] + 20;
							}
							printf("���:%d\n", ctrldb[4]);
							system("pause");
						}
						if (userchogrpet == 3)
						{
							senreader(24);
							ctrldb[6] = ctrldb[6] + 4;
							printf
								("ѡ����Ʒ\n1��DUREX\n2���ױ�\n3����ԡ¶\n4��������\n");
							if (ctrldb[6] > 300)
							{
								printf("1001.��Ϸ��Ա\n");
							}
							scanf("%d", &userbuy);
							if ((userbuy >= 1) && (userbuy <= 4))
							{
								if (userbuy == 1)
								{
									printf("����\n");
									scanf("%d", &ctrldb[114]);
									ctrldb[12] = ctrldb[12] - 15 * ctrldb[114];
									ctrldb[8] = ctrldb[8] + ctrldb[114];
									printf("DUREX�ѹ���%d��������%d��\n", ctrldb[114],
										   ctrldb[8]);
								}
								if (userbuy == 2)
								{
									printf("����\n");
									scanf("%d", &ctrldb[114]);
									ctrldb[12] = ctrldb[12] - 10 * ctrldb[114];
									ctrldb[11] = ctrldb[11] + ctrldb[114];
									printf("�ױ��ѹ���%d��������%d��\n", ctrldb[114],
										   ctrldb[11]);
								}
								if (userbuy == 3)
								{
									printf("����\n");
									scanf("%d", &ctrldb[114]);
									ctrldb[12] = ctrldb[12] - 15 * ctrldb[114];
									ctrldb[9] = ctrldb[9] + ctrldb[114];
									printf("��ԡ¶�ѹ���%d��������%d��\n", ctrldb[114],
										   ctrldb[9]);
								}
								if (userbuy == 4)
								{
									printf("����\n");
									scanf("%d", &ctrldb[114]);
									ctrldb[12] = ctrldb[12] - 15 * ctrldb[114];
									ctrldb[10] = ctrldb[10] + ctrldb[114];
									printf("�������ѹ���%d��������%d��\n", ctrldb[114],
										   ctrldb[10]);
								}
							}
							if ((userbuy != 1) && (userbuy != 2) && (userbuy != 3)
								&& (userbuy != 4) && (userbuy != 1001))
							{
								printf("ʲôҲû��\n");
							}
							if (userbuy == 1001)
							{
								if (ctrldb[6] > 1000)
								{
									gctiver(8);
								}
								if (ctrldb[6] <= 1000)
								{
									senreader(113);
								}
							}

							system("pause");
						}

						if ((userbuy == 1001) && (ctrldb[6] < 300))
						{
							printf("ʲôҲû��\n");
						}
						printf("���ʲ�:%d\n", ctrldb[12]);
						system("pause");
						system("cls");

					}

					if (userchogrpet == 4)
					{
					{
				    if(ctrldb[3]>300)
					{
					senreader(42);
					ctrldb[12] = ctrldb[12] + 100;
			ctrldb[1]=ctrldb[1]-20;
			}
                 if(ctrldb[3]<=300)
                 {
                     senreader(114);
					ctrldb[12] = ctrldb[12] + 50;
			ctrldb[1]=ctrldb[1]-30;
                 }
					system("pause");
				}
						printf("���ʲ�:%d\n", ctrldb[12]);
						system("pause");
					}
					if (userchogrpet == 5)
					{
						muctrl = 999;
					}
					if (userchogrpet == 6)
					{
						senreader(39);
						Sleep(2000);
						ctrldb[1] = ctrldb[1] + 40;
						printf("������ɣ�����ֵ%d\n", ctrldb[1]);
						system("pause");
					}
					if (userchogrpet == 7)
					{
						senreader(40);
						if (ctrldb[11] <= 0)
						{
							printf("û���ױ�\n");
						}
						if (ctrldb[11] > 0)
						{
							ctrldb[11] = ctrldb[11] - 1;
							senreader(41);
							ctrldb[2] = ctrldb[2] + 25;
						}
						printf("������%d\n", ctrldb[2]);
						system("pause");
					}







				if ((ctrldb[1]>0)&&(ctrldb[108]!=0))
				{
				    printf("�㲻�ò���취����ծ��\n");
				    if(ctrldb[3]>300)
					{
				    printf("���峥��\n");
					senreader(42);
					ctrldb[12] = ctrldb[12] + 100;
			ctrldb[1]=ctrldb[1]-20;
			}
                 if(ctrldb[3]<=300)
                 {
				    printf("��������\n");
                     senreader(114);
					ctrldb[12] = ctrldb[12] + 50;
			ctrldb[1]=ctrldb[1]-30;
                 }
					system("pause");
				}
}

			}

void thirteen()
{
				int hsone, hstwo, hsthr, hsfou, hsfiv, hsx, hsxn = 0, hanshuexit;
				system("cls");
				printf("��������\n");
				printf("1.sin mathx \n");
				printf("2.log mathx \n");
				printf("3.mathx2 \n");
				printf("4.mathx3 \n");
				printf("5.mathx^-1\n");
				scanf("%d", &hsone);
				printf("��������\n");
				scanf("%d", &hstwo);
				printf("��������\n");
				scanf("%d", &hsthr);
				printf("�����������ƫ��\n");
				scanf("%d", &hsfou);
				printf("������������ƫ��\n");
				scanf("%d", &hsfiv);
				printf("ͼ�������������\n");
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
					muctrl = 999;
				}
			}

void fourteen()
{

				int musicbase[100], musiclong, musicintlong = 400, nowscanfmusic =
					1, musicintorread = 0, musicinput = 0;
				while (musicinput != 5)
				{
					system("cls");
					printf("��Ƶ(����)������\n");
					printf("�ֶ�����(1)\n��ȡ�ļ�(2)\n");
					scanf("%d", &musicintorread);
					if ((musicintorread == 1) || (musicintorread == 2))
					{
						if (musicintorread == 1)
						{
							printf("������������\n");
							scanf("%d", &musiclong);
							printf("���뵥λ������ʱ(ms)\n");
							scanf("%d", &musicintlong);
							printf("��������\n");
							while (nowscanfmusic <= musiclong)
							{
								printf("��%d������\n", nowscanfmusic);
								scanf("%d", &musicbase[nowscanfmusic]);
								nowscanfmusic = nowscanfmusic + 1;
							}
							printf("¼�����\n");
						}
						if (musicintorread == 2)
						{
							printf("���ڶ�ȡ\n");
							musiclong = wordread(140);
							while (nowscanfmusic <= musiclong)
							{
								musicbase[nowscanfmusic] = wordread(nowscanfmusic + 140);
								nowscanfmusic = nowscanfmusic + 1;
							}
							printf("��ȡ���\n");
						}
						musicinput = 5;
					}
					else
					{
						printf("�������\n");
					}
					system("pause");
				}


				printf("��ʼ����\n");
				nowscanfmusic = 1;
				while (nowscanfmusic <= musiclong)
				{
					printf("���ڲ��ŵ�%d������\n", nowscanfmusic);
					Beep(musicbase[nowscanfmusic], musicintlong);
					nowscanfmusic = nowscanfmusic + 1;
				}
				printf("�������\n");
				printf("�����������999�˳�\n");
				int musicboxexit;
				scanf("%d", &musicboxexit);
				if (musicboxexit == 999)
				{
					muctrl = 999;
				}
			}

void fifteen()
{

				system("cls");
				int quizstrength, quiztimea, quiztimeb, deltatime, ingstrength = 1, calcore =
					1, ingchecker = 0, ingbeep = 0, printbugfixaa = 0, printbugfixab =
					0, printbugfixac = 0, printbugfixad = 0;
				printf("�豸������������v1.0\n\n\n\n");
				printf("��������ǿ��(Լ50-100)\n");
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
					printf("��ѡ������ǿ�Ѷȣ��豸���ܿ���\n");
				}
				if (quizstrength < 50)
				{
					printf("��ѡ��������ǿ�ȣ����Խ�������нϴ����\n");
				}
				printf("����������...\n");
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

						printf("���ڲ���(%d�������)\n", printbugfixad + 1);

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
				printf("���Խ�� %d\n", deltatime);
				if (autotest != 1)
				{
					system("pause");
				}
				if (autotest == 1)
				{
					Sleep(1000);
				}
				muctrl = 999;

			}

void funturner()
{
			if ((muctrl == 15) || (autotest == 1))
			{fifteen();}
			if ((muctrl == 9) || (autotest == 1))
			{nine();}
			if (muctrl == 12)
		    {twelve();}
			if (muctrl == 13)
		    {thirteen();}
			if (muctrl == 14)
		    {fourteen();}
			if ((muctrl == 8) || (autotest == 2))
			{eight();}
			if ((muctrl == 2) || (autotest == 3))
			{two();}
			if ((muctrl == 7) || (autotest == 4))
			{seven();}
			if ((muctrl == 6) || (autotest == 5))
			{six();}
			if ((muctrl == 1) || (autotest == 6))
			{one();}
			if ((muctrl == 3) || (autotest == 7))
			{three();}
			if ((muctrl == 4) || (autotest == 8))
		    {four();}
			if ((muctrl == 5) || (autotest == 9))
			{five();}
			if ((muctrl == 10) || (autotest == 10))
			{ten();}
		}

void welcome()
{
			system("cls");
			if (debug == 1)
			{
				printf("����ģʽ\n");
			}
			if (ctrldb[30] == 1)
			{
				printf("     1 to ��������\n");
			}
			if (ctrldb[31] == 1)
			{
				printf("     2 to �η�����\n");
			}
			if (ctrldb[32] == 1)
			{
				printf("     3 to ����\n");
			}
			if (ctrldb[33] == 1)
			{
				printf("     4 to ��ʼ����\n");
			}
			if (ctrldb[34] == 1)
			{
				printf("     5 to ������λ��Ӧ����\n");
			}
			if (ctrldb[35] == 1)
			{
				printf("     6 to Android�ն�ģ����\n");
			}
			if (ctrldb[36] == 1)
			{
				printf("     7 to �ݹ������ʾ\n");
			}
			if (debug == 1)
			{
				printf("     8 to �������ݿ�༭\n");
			}
			if (debug != 1)
			{
				printf("     8 to ����������\n");
			}
			if (ctrldb[38] == 1)
			{
				printf("     9 to ����ʱ��ʱ��\n");
			}
			if (ctrldb[39] == 1)
			{
				printf("    10 to ����\n");
			}
			printf("    11 to ���뿪������Կ\n");
			if (ctrldb[41] == 1)
			{
				printf("    12 to ���ӳ���\n");
			}
			if (ctrldb[42] == 1)
			{
				printf("    13 to ����ͼ�����\n");
			}
			if (ctrldb[43] == 1)
			{
				printf("    14 to ����Ƶ������\n");
			}
			if (ctrldb[44] == 1)
			{
				printf("    15 to �豸�������ܼ��\n");
			}
			if (debug == 1)
			{
				printf("    1123 to ����һ��\n\n\n");
			}
			if (superuser != 1)
			{
				printf
					("����Ȩ�����ޣ�������Ҫ���������Կ���Կ������س��򲿷�\n");
			}
			if (superuser == 1)
			{
				printf("�����û�ģʽ\n");
			}
			printf("�����Ӧ��ţ�������ģ��\n");

			scanf("%d", &muctrl);
}

void datacleaner()
{
	while (beginning <= 200)
	{
		ctrldb[xxx] = 0;
		xxx = xxx + 1;
		beginning = beginning + 1;
	}
	while (beginningpl <= 100)
	{
		ctrldatabasepl[yyy] = 0;
		yyy = yyy + 1;
		beginningpl = beginningpl + 1;
	}
}

void welcomeread()
{
	printf("�������ݿ�����...\n");
	Sleep(500);
	if (Datareader(1) == 404)
	{
		printf("δ���ֺ������ݿ�\n");
		Sleep(1500);
	}
	if (Datareader(1) != 404)
	{
		printf("Okay!\n");
		Sleep(500);
	}

	printf("�Ի�������...\n");
	Sleep(500);
	if (senreader(1) == 404)
	{
		printf("δ���ֶԻ���\n");
		Sleep(1500);
	}
	if (senreader(1) != 404)
	{
		printf("Okay!\n");
		Sleep(1500);
	}


}

void main()
{

	srand(time(0));
    datacleaner();
	menucir = 2;
    welcomeread();
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
					ctrldb[yyy] = 1;
					xxx = xxx + 1;
					yyy = yyy + 1;
				}
			}
            welcome();
			if (((muctrl == 1) && (ctrldb[30] == 1)) || ((muctrl == 2) && (ctrldb[31] == 1))
				|| ((muctrl == 3) && (ctrldb[32] == 1)) || ((muctrl == 4) && (ctrldb[33] == 1)) || ((muctrl == 5)
																						  &&
																						  (ctrldb
																						   [34] ==
																						   1))
				|| ((muctrl == 6) && (ctrldb[35] == 1)) || ((muctrl == 7) && (ctrldb[36] == 1)) || (muctrl == 11)
				|| ((muctrl == 15) && (ctrldb[44] == 1)) || ((muctrl == 13) && (ctrldb[42] == 1))
				|| ((muctrl == 14) && (ctrldb[43] == 1)) || (muctrl == 8) || ((muctrl == 9) && (ctrldb[38] == 1))
				|| ((muctrl == 10) && (ctrldb[39] == 1)) || ((muctrl == 1123) && (debug == 1)) || ((muctrl == 12)
																						 &&
																						 (ctrldb
																						  [41] ==
																						  1)))

			{
				menuerr = 0;
			}
			if ((muctrl != 5) && (muctrl != 4) && (muctrl != 8) && (muctrl != 6) && (muctrl != 14) && (muctrl != 15) && (muctrl != 3)
				&& (muctrl != 2) && (muctrl != 9) && (muctrl != 13) && (muctrl != 1) && (muctrl != 7) && (muctrl != 10)
				&& (muctrl != 11) && ((muctrl != 1123) && (muctrl != 12)))
			{
				printf("input error and try again\n");
				system("pause");
				system("cls");
			}
			if ((muctrl == 1123) && (debug != 1))
			{
				printf("input error and try again\n");
				system("pause");
				system("cls");
			}
			regmenucirchk = ctrldb[muctrl + 29];
			if ((muctrl != 8) && (muctrl != 11) && (muctrl > 0) && (muctrl <= 15) && (regmenucirchk != 1))
			{
				printf("input error and try again\n");
				system("pause");
				system("cls");
			}
			if (muctrl == 11)
			{
				if (debug == 1)
				{
					debug = 0;
					printf("����ģʽ�ѹر�\n");
					system("pause");
				}
				else
				{
					printf("������Կ\n");
					scanf("%d", &password);
					if (password == 1848030850)
					{
						debug = 1;
						printf("�Ѹ������ģʽȨ��\n");
						system("pause");
					}
					if (password == 5201314)
					{
						printf("�������ó����û�\n");
						debug = 1;
						superuser = 1;
						Sleep(1000);
						printf("�ӳ�����ȫ�����ţ��Ѹ������ģʽȨ��\n");
						system("pause");
					}
					if (password == 94705972)
					{
						txtwrite(0);
						printf("�������ݿⱸ�ݳɹ�\n");
						system("pause");
					}
					if ((password != 94705972)
						&& (password != 1848030850) && (password != 5201314))
					{
						printf("û�ж�Ӧ��Կ\n");
						system("pause");
					}
				}
			}
			if ((muctrl == 1123) && (debug == 1))
			{
				printf("Ԥ�����򼴽���ʼ\n");
				printf("����ģʽ�ѿ���\n");
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
		while ((muctrl == 1) || (muctrl == 2) || (muctrl == 6) || (muctrl == 3) || (muctrl == 4) || (muctrl == 7) || (muctrl == 9)
			   || (muctrl == 13) || (muctrl == 14) || (muctrl == 15) || (muctrl == 8) || (muctrl == 5) || (muctrl == 10)
			   || (muctrl == 1123) || (muctrl == 12))
		{funturner();}
	}
}

