#include "linear_regression_manual.c++"

int main()
{
    best_fitting_line l1;
    pair<double,double>output;

    output = l1.return_constants();
    cout<<"y = "<<output.first<<"x + "<<output.second<<endl;

    l1.add_value(1,2);
    output = l1.return_constants();
    cout<<"y = "<<output.first<<"x + "<<output.second<<endl;

    l1.add_value(2,4);
    output = l1.return_constants();
    cout<<"y = "<<output.first<<"x + "<<output.second<<endl;
    
    l1.add_value(0.6,1);
    output = l1.return_constants();
    cout<<"y = "<<output.first<<"x + "<<output.second<<endl;
}