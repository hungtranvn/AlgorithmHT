#include <iostream>
#include <cstring>
 
using namespace std;
 
#define MAX_RC (100)
 
int R, C;
unsigned int raw_decoded[MAX_RC][MAX_RC];
unsigned char encoded[(MAX_RC * 2) * (MAX_RC * 2)];
 
void Input_Data(void)
{
    int r, c;
    cin >> R >> C;
    for (r = 0; r < R; r++)
    {
        for (c = 0; c < C; c++)
        {
            cin >> raw_decoded[r][c];
        }
    }
}

int Encoding_Data(void)
{
    // 작성해야 할 함수 Complete the function code
    
 
    return 0; // encoded배열에 저장한 개수를 리턴해야 함 Return the count of items in the encoded array
}

void Decoding_Data(void) {
    short pixel_encoded;
    int pixel_R, pixel_G, pixel_B;
    int idx_encoded = 0;
 
    int padding_cnt = 4 - ((C * 2) % 4);
    if (padding_cnt == 4) padding_cnt = 0;
 
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            pixel_encoded = ((int)encoded[idx_encoded] << 8) | encoded[idx_encoded + 1];
            idx_encoded += 2;
            pixel_R = ((pixel_encoded >> 11) & 0x1f) << 3;
            pixel_G = ((pixel_encoded >> 5) & 0x3f) << 2;
            pixel_B = (pixel_encoded & 0x1f) << 3;
            raw_decoded[r][c] = (pixel_R << 16) | (pixel_G << 8) | (pixel_B);
        }
        idx_encoded += padding_cnt;
    }
}
 
void Output_Data(int len)
{
    cout << R << " " << C << '\n';
    for (int i = 0; i < len; i++)
    {
        cout << (unsigned int)encoded[i] << " ";
    }
}
 
// void Output_Data(void) {
//  cout << R << " " << C << "\n";
//  for (int r = 0; r < R; r++) {
//      for (int c = 0; c < C; c++) {
//          cout << raw_decoded[r][c] << "\n";
//      }
//      printf("\n");
//  }
// }
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int len_encoded;
    // 입력 받는 부분 Input section
    Input_Data();
 
    // 작성해야 할 함수 Function to be implemented: int Encoding_Data(void)
    len_encoded = Encoding_Data();
    // Output_Data();
    // 출력하는 부분 Output section
    Output_Data(len_encoded);
 
    return 0;
}

/*
4 3
15974662 14214476 16540990
3412884 13629328 11094264
8391323 15192188 7517293
4153032 8827344 10178575
246 0 223 41 251 39 0 0 48 18 207 50 170 95 0 0 128 83 230 15 117 45 0 0 58 121 133 26 154 1 0 0
*/

