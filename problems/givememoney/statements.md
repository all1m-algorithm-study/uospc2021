# 조공을보내줘

## 문제

 당신은 UOS 왕국의 왕입니다. UOS 왕국은 1개의 수도와 N개의 도시로 이루어져있습니다. 각 도시는 1번부터 N번까지 번호가 있고 수도와 1번 도시가, 1번 도시와 2번 도시가, ... , (N - 1)번 도시와 N번 도시가 이어져 있습니다. 즉, 3번 도시에서 수도를 방문하려면 2번,1번 도시를 거쳐야됩니다.

 모든 도시들은 수도에 조공을 보내야합니다. 조공을 보내는 방법은 간단합니다. 도시들은 순서대로 자기 차례가 되면 조공을 보냅니다. 평소에 모든 도시는 `Closed` 상태입니다. 도시는 자기 차례가 되면 상태를 `Open`으로 변경하고 조공을 보냅니다. 수도까지 가는 길에 있는 모든 도시가 `Open`인 경우에만 조공이 수도까지 도착합니다. 조공 도달에 실패하면 조공은 사라지고 모든 도시가 조공을 보낸 후 `Closed`상태로 변경합니다. 수도까지 몇 개의 조공이 제대로 도착하는지 구하는 프로그램을 작성해주세요.

## 입력

첫째 줄에 N이 입력됩니다. 둘째 줄에 N개의 도시 번호가 입력됩니다. 도시 번호는 1 <= CityNum <= N 으로 1 부터 N까지 중복되지 않는 숫자 배열입니다. 입력되는 도시 번호 순서대로 조공을 보냅니다.

## 출력

성공적으로 도착한 조공 수를 출력해주세요.

## 예시 입력1

```
5
3 4 5 1 2
```

## 예시 출력1

```
2
```

1번 도시와 2번 도시만 조공이 제대로 도착합니다.

## 예시 입력2

```
5
2 1 3 4 5
```

## 예시 출력2

```
4
```

2번 도시를 제외하고 모두 조공이 제대로 도착합니다.