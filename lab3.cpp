/*************************************************************
	???????????? ??????? ?3. ?????????? ???????.
							???????????? ????????? ??????.
							?????????? ????????? ?????????? ? ??????.
							??????? ?????????.
							??????.
*************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "vld.h"

#define	  stop __asm nop
using namespace std;
int main()
{

	///////////////////////////////////////////////////////////////
	//			?????????? ???????                               //
	///////////////////////////////////////////////////////////////

		//??????? 1. ???????? ?????????? N*M*K ?????? ? ??????????? ?????????
		//???????? ????????? ????????? ???????:
		//?) ?????????????????? ?????? ??? ??????????
		//?)* ???????? ???????????????????? ?????? ? ????????? ???????? ?????????
		//	? ??????? ????
		//					 |--------|		
		//				   / |3  3  3 |		
		//    			 |---------|3 |
		//			   / | 2  2  2 |3 |
		//			  |---------|2 |__|
		//			  | 1  1  1 |2 | /
		//			  | 1  1  1 |__| 
		//			  | 1  1  1 | /
		//			  |_________|
		//?????????? ????????? ????????? ???????????? ?????? ???????.
	const int N = 3, M = 3, K = 3;
	int arr[N][M][K] = {
		{{1,1,1},{1,1,1},{1,1,1}},
		{{2,2,2},{2,2,2},{2,2,2}},
		{{3,3,3},{3,3,3},{3,3,3}}
	};
	int a[N][M][K];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < K; k++)
			{
				a[i][j][k] = i + 1;
			}
		}
	}
	stop;
	//?) ??????? ????? ????????? ???????
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < K; k++)
			{
				s = s + a[i][j][k];
			}
		}
	}
	std::cout << s << std::endl;//54
	stop;
	//?) ?????????????????? ?????? ??? ???????????:
	//					 |--------|		
	//				   / |3  0  0 |		
	//    			 |---------|0 |
	//			   / | 2  0  0 |0 |
	//			  |---------|0 |__|
	//			  | 1  0  0 |0 | /
	//			  | 0  0  0 |__| 
	//			  | 0  0  0 | /
	//			  |_________|
	int a2[N][M][K] = {
		{ {1} },
		{ {2} },
		{ {3} }
	};//????????????? ????????? 0

	//?)* ????????????? ???????? ?????????? ??????????:
	//???????? ? ?????????????????? ?????????? ?????????? ??? ???????:
	//?????????? ?????? ? ?????? ??????????. ???????? ??????? ? ?????????????
	//????????? ????? ????????.
	char a4[][4] = { "ABC", "CBA", "KLJ" };//?????? ?????? '\0'
	char const* a5[] = { "ABC", "CBA", "KLJ" };
	//1. ???????? ?????? 3*4*sizeof(char) ??? ??????????? ??????? ? ???????? ?????????? ????????? ????????? ? ??????????????? ?????? ???????
	//2.???????? ?????? ??? ??? ????????? ??? ??????????? ???????; ??????????? ??????? ???????? ??????? ????????, ?????? ?????? ??????
	//???????????????? ?????????? ????????(?????????? ?????? ??????? ??????? ?? ??????????????? ????????? ???????).


///////////////////////////////////////////////////////////////
//			???????????? ????????? ??????                    //
///////////////////////////////////////////////////////////////
	//???????2. ???????? ???????????? ?????????? ?????? ? ?????????????,
	//???????????? ? ???????? ?????????? ????????? - N*M.
	//??????? ???????? ????????? ??????? ?????????? ????????? ?????.
	//???????  ????? ?????????.
	//????????? 1: ??? ????????? ????????? ????? ??????????? ???????
	//??????????? ?????????? - rand() (<cstdlib>)
	//????????? 2: ?? ????? ???? ?? ????????, ??????? ????????? ??????????? ?????????
	//????? ???????? ??????????????????, ?? ???? ??? ???? ???????????????? ????????
	//?????????? ?? ????????? ??? ?????????? ?????????????????? ????????.
	//??? ???? ????? ???????????? "?????????" ???????? ???? ??????? ??? ?????? 
	//??????? ?????????? ??????????? ??????? ??????????? ?????????? srand() (<cstdlib>)
	//? time() (<ctime>).
	//??????? srand() ???????????? ?????????? ?????? ????????? ? ?????????? ? ???????? ????????? ????????.
	//??????? time() ?????? ??? ????? ???????, ???????? ??????? ?????

	//srand( time( 0 ) );
	{
		srand(time(0));
		int N, M;
		std::cout << "#2 " << std::endl;
		std::cout << "N = ";
		std::cin >> N;
		std::cout << std::endl;
		std::cout << "M = ";
		std::cin >> M;
		std::cout << "size arr:" << N << 'x' << M << ':';
		int** p = new int* [N];
		for (int i = 0; i < N; i++)//231 ?????????
		{
			p[i] = new int[M];
		}
		unsigned int s = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				p[i][j] = rand() % 100;
				s = s + p[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < M; j++)
			{
				std::cout << p[i][j] << ' ';
			}
		}
		std::cout << std::endl;
		std::cout << "summa:" << s << std::endl;
		stop


			//???????2?. ? ?????????????? ??????? ???????????? ?????? ?????? ??
			//???????? ????????. ??????????? ?????????? "???????"
		{ int buf, max;
			for (int k = 0; k < N; k++) {
				for (int h = 0; h < M - 1; h++) {
					max = h;
					for (int u = h + 1; u < M; u++) {
						if (p[k][u] > p[k][max]) {
							max = u;
						}
					}
					buf = p[k][h];
					p[k][h] = p[k][max];
					p[k][max] = buf;

				}
			}
			for (int i = 0; i < N; i++)
			{
				std::cout << '\n';
				for (int j = 0; j < M; j++)
				{
					std::cout << p[i][j] << ' ';
				}
			}
		}std::cout << std::endl;

		//???????2?. ???????? ?????????? ?????? ???????????? N.
		//??????????? ???????? i-??? ???????? ??????????? ???????  
		//?????? ???????? ???????? ????????? i-?? ??????
		//??????????? ???????
		float* sr = new float[N];
		for (int i = 0; i < N; i++)
		{
			float s = 0;
			int* sum = p[i];
			for (int j = 0; j < M; j++)
			{
				s += *sum;
				sum++;
			}
			sr[i] = s / static_cast<float>(M);
		}
		std::cout << "\nSrednee znachenie:\n";
		for (int i = 0; i < N; i++)
		{
			std::cout << std::fixed;
			std::cout.precision(3);
			std::cout << sr[i] << ' ';
		}

		//????????? - ?? ???????? ?????????? ??????!
		for (int i = 0; i < N; i++)
		{
			delete[] p[i];
		}
		delete[] p;
		delete[] sr;
		p = 0; sr = 0;

		std::cout << std::endl;
	}

	/////////////////////////////////////////////////////////////////////
	//??????? 3. ?) ???????? ???????? ????, ??????? ?????? NN ????? ????? ? ???????
	//?????? ????? ? ??????????? ???? ?????????? ?????????? ??????, ?????? ???
	//???????????? ?????????? ???????? ?? ???????????
	{
		int N;
		std::cout << "\n#3a\n";
		std::cout << "N = ";
		std::cin >> N;
		int* a = new int[N];
		for (int i = 0; i < N; i++) {
			std::cout << "Insert value:"<<"\n";
			std::cin >> a[i];
			int* ma = a;
			for (int j = 0; j < i; j++) //????????? ??, ??? ??? ?????? ??????????? ?? ?????? ??????
			{
				int* pmin = ma;
				int* sl = ma + 1;
				for (int k = j + 1; k < i + 1; k++)
				{
					if (*pmin > *sl) pmin = sl;
					sl++;
				}
				int sled = *pmin;
				*pmin = *ma;
				*ma = sled;
				ma++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			std::cout << a[i] << ' ';
		}
		delete[] a;
		a = 0;
		stop;
	}

	//?) ??????? ?????.
	//????????????? ?????????? ??????? ????????? ???????:????????? ????????
	//???????? ? ?????? ?????? ??? ???????, ??? ??? ??? ?????? ??? (?? ???? 
	//????? ????????????
	{ 
		std::cout << "\n\n#3b\n";
		int N1;
		std::cout << "N1 = ";
		std::cin >> N1;
		int* a1 = new int[N1];
		for (int i = 0; i < N1; i++) {
			std::cout << "Insert value:"<< "\n";
			std::cin >> a1[i];
			int* ma = a1;
			for (int j = 0; j < i; j++)
			{
				int* pmin = ma;
				int* sl = ma + 1;
				for (int k = j + 1; k < i + 1; k++)
				{
					if (*pmin > *sl) pmin = sl;
					sl++;
				}
				int sled = *pmin;
				*pmin = *ma;
				*ma = sled;
				ma++;
			}
		}
		for (int i = 0; i < N1; i++)
		{ if (a1[i]!=a1[i+1])
			std::cout << a1[i] << ' ';
		}
		delete[] a1;
		a1 = 0;
		std::cout << std::endl;
		stop
	}

	///////////////////////////////////////////////////////////////////////////
	//??????? 4*.? ??????? ?????? ????????? ???????? ?????????,
	//???????:
	//?????? ?????? ? ?????????? ? ??????? cin>>...
	//? ??????????? ???? ?????????? ?????????? ?????? 5*80 ????????? ???? char;
	//????????? ????? ????? ???????? ?????? * (?? ???? ?????? - "*") ???
	//?????????? ??????? (?????? ????????? ????? ???);
	//?????????? ????? ? ?????????? ???????. ?????????: ??????
	//?? ????????????? ??? ?????????? ??????? ???????? ?????????
	//?????????? ?? ? ??????. ??????? ??????????? ??????? ??????
	//?????????? ?? ??????????????? ?????? ? ?????????? ??????
	//?????????.
	
	

    //?????????: ??? ????????????????? ????????? ????? ???????????
	//???????? ??????????? ?????????? strcmp(...), ???????????? ???? <string>.
	{	

		//?????????? ??????????? ???????? ??? ?????????
		const char* STOP_STRING = "*";//??????? "?????????? ????"
		const char M = 80;//???????????? ?????? ????? ??????
		const char N = 10;	//???????????? ?????????? ????? ? ???????
		


		//???????? ?????????? ?????? ? ?????? cBuffer ???? char ?
		// ???????????? N*M
		char cBuffer[N][M];

		//???????? ?????? (? ?????? cPointers) ?????????? ?? ??????
		//???????????? N
		char* cPointers[N];

		//???? ????? ?????:
		//?) ???????? ??????????? ??? ?????
		std::cout << "\n#4" << "\n" << "Insert value: " << "\n";
		//?) ???? ?? ??????? ?????? STOP_STRING ??? ?? ???????? ???? ???????
		int ks;
		for (int i = 0; i < N; i++) {


			//???? ?????? ? ?????? cBuffer:
			std::cin >> cBuffer[i];

			//???? ??????? ?????? - ??????? ?????????, ?? ????? ?? ?????
			if (strcmp(cBuffer[i], STOP_STRING) == 0) break;
			//????????? ???????? ??????? cPointers ? ???????? nIndex
			//????????? ?? ?????? ? ??????? nIndex ? ??????? cBuffer
			cPointers[i] = cBuffer[i];
			ks = i;//?????? ?????????? ????????
		}




		//?????? ??????????? ? ???, ??? ????? ????? ????????.
		std::cout << std::endl;
		std::cout << "input ending" << std::endl;


		//?????? ????????? ??????:
		std::cout << "Sorted" << std::endl;
		//???? ?????????? ????? ?? ?????? "???????????? ????????" ?
		//??????? ???????????. ?? ?????? ???????? - ????????????? ?????? 
		//??????????????? ?????
		for (int j = 1; j <= ks; j++)
		{
			bool buf = false;
			for (int i = 0; i < ks; i++)
			{
				if (strcmp(cPointers[i], cPointers[i + 1]) == 1)
				{
					swap(cPointers[i], cPointers[i + 1]);
					buf = true;
				}
			}
			for (int k = 0; k <= ks; k++) std::cout << cPointers[k] << std::endl;
			std::cout << std::endl;
			if (buf = false) break; //???? ????????? ?????????????
		}
		std::cout << "\nfinished work:" << std::endl;
		for (int i = 0; i <= ks; i++) std::cout << cPointers[i] << std::endl;
		
		


	}

	//??????? 5*. ?????????? ??????? ?4, ????????? ?? ??????????,
	//? ???????????? ??????? (???????). ??? ??? ?????? ????? ???? ?????? ?????,
	//??????????? ???????? ???? ?? ???????? ??? ?????? ?????? ????? ??????? ??????,
	//??????? ????????? ??? ?? ????????.
	//??? ???? ??????????? ????????? (?????????? ?????
	//??????????? ? ??????? ?????? ?????
    //???? ????? ?????:
	{int nStringNumber, kl;
	char el[80];
	const char* stop_str = {"*"};
	bool til = 0;
	std::cout << "\n5.\n" << std::endl;
	std::cout << " Enter the number of lines: ";
	std::cin >> nStringNumber;
	char** cPointers = new char* [nStringNumber]; // ?????????? ?????? ??? ?????? ??????????
	for (int i = 0; i < nStringNumber; i++)
	{
		std::cout << "Enter lines" << std::endl;
		std::cin >> el;
		int Size = 0;//????????
		Size = strlen(el) + 1;//1
		cPointers[i] = new char[Size];//??? ?????? ?????? ????? ??????? ??????, ??????? ????????? ??? ?? ????????
		kl = i;
		if (strcmp(el, stop_str) == 0)
		{
		 til = 1;
		break; // ???????? ???? ??????? 
		}
		strcpy(cPointers[i], el);
	}

	//???? ?????????? ????? ?? ?????? "???????????? ????????" ?
	//??????? ??????????? ???? ??????? ???????
	for (int i = 0; i < kl; i++)
	{
		for (int j = 0; j <= kl- 1; j++)
		{
			if (strcmp(cPointers[j], cPointers[j + 1]) > 0)
			{
				char* tmp = cPointers[j];
				cPointers[j] = cPointers[j + 1];
				cPointers[j + 1] = tmp;
			}
		}
	}
	std::cout << "Sorted line:" << std::endl;
	for (int i = 0; i <= ((til) ? kl - 1 : kl); i++)
	{
		std::cout << " " << cPointers[i] << std::endl;
	}
	std::cout << " " << std::endl;
	//???????????? ??????? ??????
	for (int i = 0; i <= kl; i++)
	{
		delete[] cPointers[i];
	}
	delete[] cPointers;
	cPointers = 0;
	}






	//??????? 6*. ?????????? ? ????????????? ?????????? ?? ???????????
	// ???????. ?????????????????? ?????????? ??????
	//double dArray[4][3][3] ???, ??? ???????? ?? ??????? ? ???????? ????????
	//????, ??????? ?????? ??????? ???????? ????????? ??????
	//? ???????? ?????:
	//	????:			     |--------|		
	//  				   / |4  4  4 |		
	//					 |--------|	4 |	
	//				   / |3  3  3 |	4 |	
	//    			 |---------|3 |   |
    //			   / | 2  2  2 |3 | /
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__| 
	//			  | 1  1  1 | /
	//			  |_________|

	//	?????:			     |--------|		
	//  				   / |3  3  3 |		
	//					 |--------|	3 |	
	//				   / |4  4  4 |	3 |	
	//    			 |---------|4 |   |
    //			   / | 1  1  1 |4 | /
	//			  |---------|1 |__|
	//			  | 2  2  2 |1 | /
	//			  | 2  2  2 |__| 
	//			  | 2  2  2 | /
	//			  |_________|
	{ double dArray[4][3][3] = {
	 {{1,1,1},{1,1,1},{1,1,1}},
	 {{2,2,2},{2,2,2},{2,2,2}},
	 {{3,3,3},{3,3,3},{3,3,3}},
	 {{4,4,4},{4,4,4},{4,4,4}}
	};
	for (int i = 0; i < 4; i+=2)
	{
		double(*nc)[3] = dArray[i]; //?????? ?????????? ?? ?????? ????????? ????
		double(*c)[3] = dArray[i + 1];
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				swap(nc[j][k], c[j][k]);
			}
		}

		//?????????: ?? ????? ?????????????? ????????? ?????? ?? ????? ?????????!!!
		//... = dArray[i];
		//... = dArray[i + 1];
		//???????????? ??????? ???????? i-???? ? i+1-??? ?????


	}stop 
	}

	///////////////////////////////////////////////////////////////////////////
	//??????? 7?. ???????? ?????????? ?????????? ?????? ????????? ???? char.
	//??????????? ???????? ????????? ??????? ? ??????? ?????????? ????????? 
	//????? ????? ???????, ????? ? ??????? ???? ?????? ??????? '*' ? '_'  
	{
		srand(time(0));
		const int X = 10, Y = 6;
		char u[X][Y];
		std::cout << "\n7a\n";

		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				int chet = rand() % 2;
				if (chet == 0) { u[i][j] = '*'; }
				else { u[i][j] = '_'; }
				std::cout << u[i][j] << " ";
			}
			std::cout << std::endl;
		}
		//? ?????? ?????? "???????? ?????????" ? ?????? ??????, ????????:
		//???? - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
		//?????: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
		//? ???????????? ?????? ?? ??????? - "????????? ?????????????"

		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				bool end = false;
				for (int k = 0; k < Y - 1; k++)
				{
					if (u[i][k] == '_')
					{
						swap(u[i][k], u[i][k + 1]);
						end = true;
					}
				}
				if (!end) break;

			}
		}
		for (int i = 0; i < X; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < Y; j++)
			{
				std::cout << u[i][j] << ' ';
			}
		}std::cout << "\n\n\n\n\n";
	}

		// 7?. ????????????? ?????????? ??????? ????????? ????????:
		//????? ?????????? ??????? ? ??????? ?????????? ????????? ?????
		//"????????" ????????? ?? ???????? ???? ? ???????????? ??????????
		//"?????????????"
	{

		srand(time(0));
		const int X = 10, Y = 6;
		char u[X][Y];
		char* pu[X];
		std::cout << "7b" << "\n";

		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				int chet = rand() % 2;
				if (chet == 0) { u[i][j] = '*'; }
				else { u[i][j] = '_'; }
				std::cout << u[i][j] << " ";
			}
			std::cout << std::endl;
			pu[i] = u[i];
	    }
		for (int i = 0; i < Y; i++)
		{
			for (int j = 1; j < X; j++)
			{
				bool end = false;
				for (int k = 0; k < X - j; k++) //????? ??? ????????????? ???????, ??????? ??? ????? ??????
				{
					if (u[k][i] < u[k + 1][i])
					{
						swap(u[k][i], u[k + 1][i]);
						end = true;
					}
				}
				if (!end) break;

			}
	
		
		}
		for (int i = 0; i < X; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < Y; j++)
			{
				std::cout << u[i][j] << ' ';
			}
		}
	}
	return 0;
}
