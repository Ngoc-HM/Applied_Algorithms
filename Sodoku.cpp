#include <iostream>

using namespace std;

// tạo ra ma trận kích thước N*N
#define N 9

/*in ma tran */
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << "|";
        cout << endl;
        cout << "- - - - - - - - -" << endl;
    }
}

// kiem tra
// legal to assign num to the
// given row, col
bool isSafe(int grid[N][N], int row,
            int col, int num)
{
    // kiểm tra nếu trùng số của hàng hoặc cột thì sẽ trả về false
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    int startRow = row - row % 3,
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// thử các giá trị gán và chạy các khả năng
bool solveSudoku(int grid[N][N], int row, int col)
{
    // kiểm tra xem đã tới 8 chưa
    // cột và hàng tới số 9 thì sẽ bằng 0
    // nếu như hàng và cột thì sẽ trả về
    // further backtracking
    if (row == N - 1 && col == N)
        return true;

    // kiểm tra xem cột có bằng 9 chưa
    //  nếu đã kt xong cột thì next hàng
    //   cột bắt đầu từ 0
    if (col == N)
    {
        row++;
        col = 0;
    }

    // kiểm tra giá trị hiện tại nếu như đã có giá trị rồi thì nhảy cột tiếp theo
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {

        // kiểm tra xem có đặt được giá trị từ 1-9 hay không
        // chuyển sang cột tiếp theo
        if (isSafe(grid, row, col, num))
        {

            // gán số hiện tại hàng, cột
            // vị trí của lưới soduku
            grid[row][col] = num;

            //  kiểm tra với giả năng tiếp theo
            //  cột
            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        // xóa số đã gán nếu giả thuyết đã sai và tiếp tục thử số khác với giá trị num khác
        grid[row][col] = 0;
    }
    return false;
}

// Driver Code
int main()
{
    // giá trị bằng 0 có nghĩa là chưa được gán
    int a[N][N];
    cout << "Nhap ma tran Soduku" << endl;
    for(int i=0;i<N;i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >>a[i][5] >>a[i][6] >>a[i][7] >>a[i][8];
    // int grid[N][N] = {  {0, 7, 0, 8, 0, 0, 0, 9, 0},
    //                     {9, 0, 0, 0, 7, 0, 0, 0, 3},
    //                     {0, 0, 0, 5, 0, 0, 0, 7, 0},
    //                     {1, 0, 0, 0, 8, 4, 0, 0, 0},
    //                     {7, 0, 0, 0, 0, 0, 0, 8, 1},
    //                     {8, 0, 0, 0, 5, 0, 4, 0, 0},
    //                     {0, 0, 0, 0, 0, 0, 9, 2, 0},
    //                     {4, 9, 0, 0, 0, 3, 1, 0, 8},
    //                     {0, 0, 6, 0, 2, 8, 3, 0, 0}
    //                   };

    if (solveSudoku(a, 0, 0))
        print(a);
    else
        cout << "khong co ket qua" << endl;
    return 0;
}