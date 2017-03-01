#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	srand(time(0));
    char characters1[19]={'1','#','9','.','F','X','s','j','\"','!','B','q','+','c',',','6','o','W','A'};
    char characters2[19]={'T','R','e','D','@','L','n','N','{',':','}','a','=','[','x','Q','Y','\ ','>'};
    char characters3[19]={'5','*','$','O','g','4','m','Z','u',')','_','V','^','2','?','t','(','-','&'};
    char characters4[19]={'|','K','/','M','k','I','0','U','b','J','S','v','y','d',';','r','p','f','E'};
    char characters5[19]={'`','H','l','%','G','i','7',']','z','~','P','C','h','3','\'','\\','<','8','w'};
    int N, K, O, M, L;
    string S, R;
    cout << "Enter 1 to encode, or 2 to decode: ";
    cin >> O;
    if (O == 1)
        cout << "Enter what you are encoding: ";
    else
        cout << "Enter what you are decoding. To paste, right click and select \"Paste\": ";
    cin.ignore();
    getline(cin, S);
    N = S.length();
    M = N;
	if (O == 1)
		cout << "Enter a password, or enter 0 for random integer password: ";
	else
		cout << "Enter your password: ";
    cin >> K;
	if (K == 0)
		K = rand() * rand();
    L = K;
    if (K%19 == 0)
        K = 10;
    else
    K %= 19;
    if (O == 1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 19; j++)
            {
            if (S.at(i) == characters1[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters2[(19+j+K)%19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters3[(19 + j + K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters4[(19 + j + K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters5[(19 + j + K) % 19];
				else
					S.at(i) = characters1[(19 + j + K) % 19];
				j = 19;
            }
            else if (S.at(i) == characters2[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters3[(19 + j + K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters4[(19 + j + K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters5[(19 + j + K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters1[(19 + j + K) % 19];
				else
					S.at(i) = characters2[(19 + j + K) % 19];
				j = 19;
            }
            else if (S.at(i) == characters3[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters4[(19 + j + K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters5[(19 + j + K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters1[(19 + j + K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters2[(19 + j + K) % 19];
				else
					S.at(i) = characters3[(19 + j + K) % 19];
				j = 19;
            }
            else if (S.at(i) == characters4[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters5[(19 + j + K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters1[(19 + j + K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters2[(19 + j + K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters3[(19 + j + K) % 19];
				else
					S.at(i) = characters4[(19 + j + K) % 19];
				j = 19;
            }
            else if (S.at(i) == characters5[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters1[(19 + j + K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters2[(19 + j + K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters3[(19 + j + K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters4[(19 + j + K) % 19];
				else
					S.at(i) = characters5[(19 + j + K) % 19];
				j = 19;
            }
            else;
            }
        }
        R = S;
        for (int i = 0; i < N; i++)
        {
            R.at(M-1) = S.at(i);
            M--;
		}
        S = R;
		system("CLS");
        cout << "\n\n\tYour code is between the blocks, don't forget spaces at the\n\tbeginning/end: \xDE" << S << "\xDD\n\tPassword: " << L << "\n\n\tTo select, right click and press \"Mark,\" then click and drag over the\n\tcode so that it turns into a long white box. If the box gets separated\n\tby a black rectangle you've gone too far.\n\tOnce selected, press \"Enter\" on your keyboard to copy to clipboard.\n\t";
        if (L != K)
            cout << "(Alternate short password: " << K << ")\n\n\t";
    }
    else if (O == 2)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 19; j++)
            {
            if (S.at(i) == characters1[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters5[(19 + j - K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters4[(19 + j - K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters3[(19 + j - K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters2[(19 + j - K) % 19];
				else
					S.at(i) = characters1[(19 + j - K) % 19];
				j = 19;
            }
            else if (S.at(i) == characters2[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters1[(19 + j - K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters5[(19 + j - K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters4[(19 + j - K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters3[(19 + j - K) % 19];
				else
					S.at(i) = characters2[(19 + j - K) % 19];
				j = 19;
            }
            else if (S.at(i) == characters3[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters2[(19 + j - K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters1[(19 + j - K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters5[(19 + j - K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters4[(19 + j - K) % 19];
				else
					S.at(i) = characters3[(19 + j - K) % 19];
				j = 19;
            }
            else if (S.at(i) == characters4[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters3[(19 + j - K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters2[(19 + j - K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters1[(19 + j - K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters5[(19 + j - K) % 19];
				else
					S.at(i) = characters4[(19 + j - K) % 19];
				j = 19;
            }
            else if (S.at(i) == characters5[j])
            {
				if (K >= 1 && K <= 5)
					S.at(i) = characters4[(19 + j - K) % 19];
				else if (K >= 6 && K <= 9)
					S.at(i) = characters3[(19 + j - K) % 19];
				else if (K >= 10 && K <= 13)
					S.at(i) = characters2[(19 + j - K) % 19];
				else if (K >= 14 && K <= 18)
					S.at(i) = characters1[(19 + j - K) % 19];
				else
					S.at(i) = characters5[(19 + j - K) % 19];
				j = 19;
            }
            else;
            }
        }
        R = S;
        for (int i = 0; i < N; i++)
        {
            R.at(M-1) = S.at(i);
            M--;
        }
        S = R;
		system("CLS");
        cout << "\n\n\tYour decoded message is: " << S << "\n\n\t";
    }
    return 0;
}