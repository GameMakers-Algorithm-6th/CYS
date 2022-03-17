#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<pair<int, int>> q;

	bool map[101][101] = {};
	bool mapRG[101][101] = {};
	string picture[101] = {};

	int N, result = 0, resultRG = 0;

	cin >> N;

	// �׸� ���
	for (int i = 0; i < N; ++i)
	{
		cin >> picture[i];
	}

	// ���� ������ ���� Ž��
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// ������ �� ����
			int areaChar = picture[i][j];

			// Ž���� �ߴ� ������ Ȯ��
			if (!map[i][j])
			{
				// ���ʴ�� Ž�� ��ġ ����
				q.push(make_pair(i, j));

				// Ž������ �������̱⿡ ���ο� ����
				++result;

				// ���ο� ���� ���� Ž��
				while (!q.empty())
				{
					auto [row, coloum] = q.front();
					q.pop();

					// �ڱ� ������ �ƴϰ� �̹� Ž���������̶�� �н�
					if (map[row][coloum] || picture[row][coloum] != areaChar)
						continue;

					// Ž�� �Ϸ� ǥ��
					map[row][coloum] = true;

					// �ڽ��� �ֺ������� ���ٸ� ���̰ų� Ž���ߴ����� �ƴ϶�� Ž�� ���� �߰�
					if (row != 0)			q.push(make_pair(row - 1, coloum));
					if (row != N - 1)		q.push(make_pair(row + 1, coloum));
					if (coloum != 0)		q.push(make_pair(row, coloum - 1));
					if (coloum != N - 1)	q.push(make_pair(row, coloum + 1));
				}
			}

			// ���� ���� Ž���� �ߴ� ������ Ȯ��
			if (!mapRG[i][j])
			{
				// ���� ����
				q.push(make_pair(i, j));
				++resultRG;

				while (!q.empty())
				{
					auto [row, coloum] = q.front();
					q.pop();

					if (mapRG[row][coloum])
						continue;

					// Ž�� ���� ���ڰ� �Ķ��̸�
					if (areaChar == 'B')
					{
						// �Ķ��� �ƴҰ�� �н�
						if (picture[row][coloum] != areaChar)
							continue;
					}
					// Ž�� ������ �����̸�
					else
					{
						// �Ķ��� ��� �н�
						if (picture[row][coloum] == 'B')
							continue;
					}



					mapRG[row][coloum] = true;

					if (row != 0)			q.push(make_pair(row - 1, coloum));
					if (row != N - 1)		q.push(make_pair(row + 1, coloum));
					if (coloum != 0)		q.push(make_pair(row, coloum - 1));
					if (coloum != N - 1)	q.push(make_pair(row, coloum + 1));
				}
			}
		}
	}

	cout << result << ' ' << resultRG << endl;
}