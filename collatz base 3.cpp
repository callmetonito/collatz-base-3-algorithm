#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void next_state(string& sequence)
{
    string result;
    result.reserve(sequence.size()+ 1);

    int operation = 0;

    for (char digit : sequence)
    {
        if (operation == 0)
        {
            if (digit == '0')
            {
                result.push_back('0');
                operation = 0;
            }
            else if (digit == '1')
            {
                result.push_back('0');
                operation = 1;
            }
            else // digit == '2'
            {
                result.push_back('1');
                operation = 0;
            }
        }
        else // operation == 1
        {
            if (digit == '0')
            {
                result.push_back('1');
                operation = 1;
            }
            else if (digit == '2')
            {
                result.push_back('2');
                operation = 1;
            }
            else // digit == '1'
            {
                result.push_back('2');
                operation = 0;
            }
        }
    }
	// Append 2 if last operation is set to 1 
	if (operation == 1) 
	{
		result.push_back('2');
	}
	// Remove leading zero
    if (!result.empty() && result[0] == '0')
    {
        result.erase(0, 1);
    }

    sequence = result;
    
}

int main()
{
    string input;

    cout << "Enter sequence\n";
    cout << "Example: 112001\n\n> ";

    cin >> input;

	string sequence = input.substr(0);

    long long step = 0;

    while (true)
    {
        cout << "Step " << step << ": "
             << sequence << "\n";

        // Stop condition
        if (sequence == "1")
        {
            cout << "DONE\n";
            break;
        }

        next_state(sequence);

        step++;
    }

    cout << "\nPress ENTER to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
