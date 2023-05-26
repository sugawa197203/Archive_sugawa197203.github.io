# MCC C言語部内講習会 第2回

## この講座の対象の人
 - MCC部員
 - C言語を初歩から学びたい人


**この後の内容をチラ見して内容を知っていそうだと判断できる人は次回以降の参加でも大丈夫です！**


## ポインタ編

誰もが苦しむところです。覚悟してください。ポインタをマスターしたら神になれます。はじめはちょっとだけ座学です。

### メモリ

ここではメモリについてちょっとだけ学びます。ハード的な仕組みは触れません。ソフト的な概念のみです。ハード的な部分はA科の2年後期のASコースの計算機アーキテクチャの授業で習います。

### bit

コンピューターでは2進数でデータを扱います。10進数と2進数の変換は高校で習ったと思います。
**bit**(ビット)とは0か1を表す最小単位です。0101は4bit, 111000は6bit, 00110011は8bitです。

### byte

基本的なコンピューターでは数値を8bitずつ扱います。8bit集まったものを**1byte**(バイト)と呼びます。
1byteは8bitなので10進数で0～255までの数値を表すことが可能です。
byte数が大きくなると略したりします。
1024byteで1Kbyte(キロバイト)、1024Kbyteは1Mbyte(メガバイト)、1024Mbyteで1Gbyte(ギガバイト)、1024Gbyteで1Tbyte(テラ)という風に略します。

|接頭語|記号|byte|
|:--|:-:|--:|
|クエタ quetta|Q|1Qbyte|
|ロナ ronna|R|1Rbyte|
|ヨタ yotta|Y|1Ybyte|
|ゼタ zetta|Z|1Zbyte|
|エクサ exa|E|1Ebyte|
|ペタ peta|P|1Pbyte|
|テラ tera|T|1Tbyte|
|ギガ giga|G|1Gbyte|
|メガ mega|M|1Mbyte|
|キロ kiro|K|1Kbyte|

### メモリは並んだbyte

メモリにはbyteが一列に並んでいます。4Gbyteと言われたら、約43億個の1byteが並んでいると考えてください。
先頭から順に1byteずつ番号が振られています。これが**メモリアドレス**です。

### C言語でメモリアドレスを確認

C言語で変数のアドレスを確認してみましょう。
アドレスを確認するのにポインタ変数というものを使います。
ポインタ変数は変数の前に*(アスタリスク)を付けます。変数のアドレスは変数名の前に&(アンド)をつけることで取得できます。

```c
#include <stdio.h>

int main(void)
{
	int a = 10;
	int *p = &a;	// a のアドレスを取得し ポインタ変数 p に代入

	printf("a = %d\n", a);
	printf("Address is : %p\n", p);
	printf("Address decimal number : %u\n", p);
}
```

printfでフォーマット指定子がそれぞれ %d, %p, %u になっていることに注意してください。
フォーマット指定子についてはそのうち触れます。

コンパイルの警告は無視して大丈夫です。

aの中身とそのアドレスが16進数で表示されたと思います。何回か実行してみましょう。毎回値が変わると思います。

続いて配列のアドレスを確認します。

```c
#include <stdio.h>

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int *p = a;
	int *p0 = &a[0];
	int *p1 = &a[1];
	int *p2 = &a[2];
	int *p3 = &a[3];
	int *p4 = &a[4];

	printf("a is : %p\n", p);
	printf("a0 is : %p\n", p0);
	printf("a1 is : %p\n", p1);
	printf("a2 is : %p\n", p2);
	printf("a3 is : %p\n", p3);
	printf("a4 is : %p\n", p4);
}
```

int *p = a; で &a ではなく a であることに注意してください。

a と a[0] のアドレスが一致することがわかると思います。また、a[0]～a[4]まで、アドレスが4ずつ増えてるのがわかると思います。
これは a のアドレス自体は a[0] のアドレスを指しており、a[0]～a[4]はメモリ上で32bit(4byte)ずつ連続して存在しているからです。

p に a のアドレスを代入するとき、&が必要ないことから次のようなプログラムが作れることに気がつく人がいると思います。

```c
#include <stdio.h>

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int *p = a;

	for(int i = 0; i < 5; i++){
		printf("%d\n", p[i]);
	}
}
```

配列みたいに動作したと思います。
しかし ポインタ=配列 の関係ではありません。勘違いしないでください。
配列は[]演算子でアドレスにインデックス番号の値だけ足して要素にアクセスします。
そのため、似たような使い方でポインタにもできるだけです。

### Swap関数(参照渡し)

2つの変数の数値を入れ替えるSwap関数を実装しましょう。

```c
#include <stdio.h>

void swap(int a, int b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void)
{
	int x, y;
	x = 5;
	y = 3;
	
	printf("x = %d, y = %d\n", x, y);

	swap(x, y);

	printf("x = %d, y = %d\n", x, y);
}
```

入れ替わりません。x,y,a,bのアドレスを確認してみましょう。

```c
#include <stdio.h>

void swap(int a, int b){
	printf("&a = %p, &b = %p\n", &a, &b);
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void)
{
	int x, y;
	x = 5;
	y = 3;
	
	printf("x = %d, y = %d\n", x, y);
	printf("&x = %p, &y = %p\n", &x, &y);

	swap(x, y);

	printf("x = %d, y = %d\n", x, y);
	printf("&x = %p, &y = %p\n", &x, &y);
}
```

xとyのアドレスはswap関数を呼び出す前と後で変わらないと思います。aとbのアドレスはxとyのアドレスと異なっていると思います。このことからa,bはx,y自体を触れていないことがわかります。

swap関数でx,yを直接触るにはx,yの数値をswapに渡すのではなく、x,yのアドレスを渡しましょう。swap関数内で、アドレスから数値を触るには*を変数名の前につけます。アドレスから数値をさわれれば、取得、代入ができます。

アスタリスクの位置に注意して実装しましょう。

```c
#include <stdio.h>

void swap(int *a, int *b){
	printf("a = %p, b = %p\n", a, b);
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int x, y;
	x = 5;
	y = 3;
	
	printf("x = %d, y = %d\n", x, y);
	printf("&x = %p, &y = %p\n", &x, &y);

	swap(&x, &y);

	printf("x = %d, y = %d\n", x, y);
	printf("&x = %p, &y = %p\n", &x, &y);
}
```

x,yのアドレスを渡すことで2つの変数の数値を入れ替えるSwap関数が完成しました。

### ポインタ実践

```c
#include <stdio.h>

int main(void)
{
	int a = 334;
	int *ap = &a;

	printf("a Address is %p\n", ap);
	printf("a = %d\n", a);

	*ap = 255;

	printf("a = %d\n", a);
}
```

Segmentation fault (core dumped)

```c
#include <stdio.h>

int main(void)
{
	int a = 334;
	int *ap = &a;

	printf("a Address is %p\n", ap);
	printf("a = %d\n", a);
	printf("a = %d\n", *ap);

	ap = 255;

	printf("a = %d\n", a);
	printf("a = %d\n", *ap);
}
```



アドレスの確認を他の型でも確認してみましょう

```c
#include <stdio.h>

int main(void)
{
	char c = 'a';
	char ac[] = "abc";
	char *cp = &c;
	char *acp = ac;

	printf("c = %c\n", c);
	printf("Address is : %p\n", cp);
	printf("Address decimal number : %u\n", cp);

	for(int i = 0; i < 3; i++){
		printf("Address char is : %p\n", &ac[i]);
	}



	short s = 1;
	short as[] = {1, 2, 3, 4, 5};
	short *sp = &s;
	short *asp = as;

	printf("s = %d\n", s);
	printf("Address is : %p\n", sp);
	printf("Address decimal number : %u\n", sp);

	for(int i = 0; i < 5; i++){
		printf("Address char is : %p\n", &as[i]);
	}



	long l = 1;
	long al[] = {1, 2, 3, 4, 5};
	long *lp = &l;
	long *alp = alp;

	printf("l = %d\n", l);
	printf("Address is : %p\n", lp);
	printf("Address decimal number : %u\n", lp);

	for(int i = 0; i < 5; i++){
		printf("Address char is : %p\n", &al[i]);
	}
}
```

ポインタ変数はインクリメントが使えます。


```C
#include <stdio.h>

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int *p = a;

	for(int i = 0; i < 5; i++){
		printf("%d\n", *p++);
	}
}
```

