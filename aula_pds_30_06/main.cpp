#include <iostream>
#include <vector>

using namespace std;

int main()
{
    try
    {
        vector<int> v[5];
        int i;
        cin i;
        v.at(i) << endl;
    }
    catch (out_of_range e)
    {
        cout << "Indice invalido!" << endl;
    } catch(bad_alloc e) {
        cout << "Memória insuficiente!" << endl;
    }

    return 0;
}
