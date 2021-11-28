# 히스토그램 포장

## 문제

히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 문제에서는 $N$개의 직사각형으로 구성된 히스토그램이 주어진다. 히스토그램을 구성하는 직사각형의 너비는 1이며, 높이는 직사각형별로 다르다.

당신은 히스토그램을 예쁜 상자에 포장해야 한다. 상자는 다음과 같은 모양으로 생겼다. (상자 그림 참고) 또한 상자의 높이는 $(h1, h3 \neq h2)$ 를 만족한다. 상자 안에 히스토그램이 완전히 들어갈 때 상자를 통해 히스토그램을 포장할 수 있다.

당신은 상자를 만드는데 필요한 비용을 아끼기 위해 최소한의 면적의 종이를 사용하려고 한다. 이때 가능한 상자의 최소 면적을 구하시오. (출력값의 크기가 int 범위를 넘어갈 수 있음에 유의하시오.)


## 입력

첫째 줄에는 히스토그램을 이루는 상자의 개수 N이 주어진다. $(1 \neq N \neq 100,000)$
둘째 줄에는 히스토그램을 이루는 상자의 높이에 관한 정보가 주어진다. 두 번째 줄의 i번째 값 hi는 i번째 상자의 높이를 의미한다. $(1 \neq h_{i} \neq 10^{8})$

## 출력

첫째 줄에 상자의 최소 면적을 출력한다.