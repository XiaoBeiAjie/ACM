#include <random>
#include <fstream>

using namespace std;

int main()
{
    ofstream ofs("111.txt");

    constexpr int N = 1e6;

    vector<char> table(26 * 2);
    iota(table.begin(), table.begin() + 26, 'a');
    iota(table.begin() + 26, table.end(), 'A');

    constexpr int block_size = 100;
    constexpr int n = N / block_size;
    ofs << n << '\n';
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> uni(0, 26 * 2 - 1);
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < block_size; j++)
        {
            s += table[uni(rng)];
        }
        ofs << s << ' ';
    }
    ofs << '\n';
}