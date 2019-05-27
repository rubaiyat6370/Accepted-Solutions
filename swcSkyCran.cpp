
//main
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(char* arg_obj);
extern void add(char* arg_obj);
extern void remove(char* arg_obj);
extern int search_max(char* arg_obj);
extern int calc_sum(char* arg_obj);

#define ADD_QUERY 1
#define REM_QUERY 2
#define MAX_QUERY 3
#define SUM_QUERY 4

int testFromInputFile();
int testFromRandom();

int main(){
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int points = testFromInputFile();
	points += testFromRandom();
	printf("---------------\ntotal points: %d\n", points);

	return 0;
}


int testFromInputFile(){
	int tests;
	scanf("%d", &tests);

	int totalUserPoints = 0;

	for (int t = 0; t < tests; t++){
		char arg_obj[200] = { 0 };
		scanf("%s", arg_obj);
		init(arg_obj);

		int queries;
		scanf("%d", &queries);

		int queryType;
		int userResult, actualResult;
		int userPoints = 0, actualPoints = 0, point = 0;
		for (int q = 0; q < queries; q++){
			scanf("%d", &queryType);
			if (queryType == ADD_QUERY){
				scanf(" %[^\r\n]", arg_obj);
				add(arg_obj);
			}
			else if (queryType == REM_QUERY){
				scanf(" %[^\r\n]", arg_obj);
				remove(arg_obj);
			}
			else if (queryType == MAX_QUERY){
				scanf("%d %[^\r\n]", &actualResult, &arg_obj);
				userResult = search_max(arg_obj);

				actualPoints++;
				if (actualResult == userResult){
					userPoints++;
				}
			}
			else {
				scanf("%d %[^\r\n]", &actualResult, &arg_obj);
				userResult = calc_sum(arg_obj);

				actualPoints++;
				if (actualResult == userResult){
					userPoints++;
				}
			}
		}
		if (actualPoints == userPoints){
			point = 1;
			totalUserPoints++;
		}
		printf("test %d: %d\n", t, point);
	}

	return totalUserPoints;
}


static int seed;
static int pseudo_rand(void){
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0X7FFF;
}
static int pseudo_rand(int range){
	return pseudo_rand() % range;
}

#define N_T 10
static int s = 3;
static int _rand(){
	s = s * 21413 + 253111;
	return ((s >> 16) & 0X7FFF) % N_T;
}

char noises1[N_T][5] = { "", " ", "  ", "   ", "", "", "", " ", "", " " };
char noises2[N_T][15] = { "", " leng : 34 ,", "", "xy :4,", "yy :12, ", "H:9  , ", "wh : 78,", "ok:9,", "", "voot:876  ," };

int testFromRandom(){
	int L = 801;
	int W = 201;
	int MAX_H = 37;
	int CALL = 900000;
	int CALL_ADD = 500000;
	int CALL_REM = 400000;
	int CALL_SUM = 10000;
	int CALL_MAX = 10000;

	int tests;
	scanf("%d", &tests);

	scanf("%d", &seed);

	int totalUserPoints = 0;

	for (int t = 0; t<tests; t++){
		char arg_obj[200] = { 0 };

		int length = L / 2 + pseudo_rand(L - L / 2);
		int width = W / 2 + pseudo_rand(W - W / 2);
		sprintf(arg_obj, "{%slength:%s%d,%swidth%s:%d%s}", noises1[_rand()], noises1[_rand()], length, noises2[_rand()],
			noises1[_rand()], width, noises1[_rand()]);
		init(arg_obj);

		int x, y, h, l, w, queryType;
		int actualHash, userHash = 0, point = 0;
		int addCalls = 0, remCalls = 0, sumCall = 0, maxCall = 0;
		for (int j = 0; j < CALL; j++){
			queryType = pseudo_rand(100);
			x = pseudo_rand(length) + 1;
			y = pseudo_rand(width) + 1;

			if (queryType<50){
				if (addCalls <= CALL_ADD){
					h = pseudo_rand(MAX_H) + 1;
					sprintf(arg_obj, "{%sx:%s%d,%s%sh%s:%d%s,%sy%s:%d}", noises1[_rand()], noises1[_rand()], x,
						noises2[_rand()], noises1[_rand()], noises1[_rand()], h, noises1[_rand()],
						noises2[_rand()], noises1[_rand()], y);
					add(arg_obj);
					addCalls++;
				}
			}
			else if (queryType<90){
				if (remCalls <= CALL_REM){
					sprintf(arg_obj, "{%sx:%s%d,%sy%s:%s%d}", noises1[_rand()], noises1[_rand()], x, noises2[_rand()],
						noises1[_rand()], noises1[_rand()], y);
					remove(arg_obj);
					remCalls++;
				}
			}
			else if (queryType<95){
				if (sumCall <= CALL_SUM){
					l = pseudo_rand(length - x + 1);
					w = pseudo_rand(width - y + 1);
					sprintf(arg_obj, "{%sw%s:%d,%sx:%s%d,%s%sl%s:%d%s,%sy%s:%d}", noises2[_rand()], noises1[_rand()], w,
						noises1[_rand()], noises1[_rand()], x, noises2[_rand()],
						noises1[_rand()], noises1[_rand()], l, noises1[_rand()],
						noises2[_rand()], noises1[_rand()], y);
					userHash ^= calc_sum(arg_obj);
					sumCall++;
				}
			}
			else {
				if (maxCall <= CALL_MAX){
					l = pseudo_rand(length - x + 1);
					w = pseudo_rand(width - y + 1);
					sprintf(arg_obj, "{%sy%s:%d,%sl:%s%d,%s%sx%s:%d%s,%sw%s:%d}", noises1[_rand()], noises1[_rand()], y,
						noises2[_rand()], noises1[_rand()], l, noises2[_rand()],
						noises1[_rand()], noises1[_rand()], x, noises1[_rand()],
						noises2[_rand()], noises1[_rand()], w);
					userHash ^= search_max(arg_obj);
					maxCall++;
				}
			}
		}

		if (userHash < 0){
			userHash = -userHash;
		}
		scanf("%d", &actualHash);

		if (actualHash == userHash){
			totalUserPoints++;
			point = 1;
		}

		printf("test %d: %d\n", t + 2, point);
	}

	return totalUserPoints;
}
