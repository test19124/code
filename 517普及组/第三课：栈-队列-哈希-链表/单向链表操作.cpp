#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	int num;
	int to;
} a[10010];
int tot = 1;

bool find(int x) {
  int i = 1;
	bool flag = false;
	while(1) {
		if(x == -1) {
			printf("%d ", a[i].num);
		} else {
			if(a[i].num == x) {
				flag = true;
				break;
			}
		}
		if(a[i].to == 0) {
			break;
		}
		i = a[i].to;
	}
	if(x == -1) {
		printf("\n");
	}
	return flag;
}

bool add(int x,int y) {
	int i = 1;
	if(find(y)) {
    return false;
	}
	while(1) {
		if(a[i].num == x) {
			tot++;
			a[tot].num = y;
			a[tot].to = a[i].to;
			a[i].to = tot;
			return true;
		}
		if(a[i].to == 0) {
			break;
		}
		i = a[i].to;
	}
	return false;
}

bool detel(int x) {
	int i = 1;
	while(1) {
		if(a[i].to == 0) {
      break;
		}
		if(a[a[i].to].num == x) {
			a[i].to = a[a[i].to].to;
			return true;
		}
		i = a[i].to;
	}
	return false;
}

int main() {
	scanf("%d",&n);
	int k,x,y;
	for(int i = 1; i <= n; i++) {
    scanf("%d",&k);
		if(k == 1) {
			scanf("%d%d",&x,&y);
      if(add(x,y)) {
				printf("ok\n");
			} else {
				printf("error\n");
			}
		} else {
			scanf("%d",&x);
      if(detel(x)) {
				printf("ok\n");
			} else {
				printf("error\n");
			}
		}
	}
	find(-1);
	return 0;
}