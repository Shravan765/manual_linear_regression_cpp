#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

//fitting the line by minimising squared error
class best_fitting_line
{
    public:
        best_fitting_line(){ A = C = 0; X_values = {}; y_values = {}; }

        best_fitting_line(vector<int>x, vector<int>y){ //a list of x and y values, int
            A = C = 0;
            for(int i : x)
            {
                X_values.push_back({i,1});
            }
            for(int i : y)
            {
                y_values.push_back(i);
            }
        }
        best_fitting_line(vector<double>x, vector<double>y){ //a list of x and y values, double
            A = C = 0;
            for(double i : x)
            {
                X_values.push_back({i,1});
            }
            y_values = y;
        }
        //adding a single value while initialising
        best_fitting_line(double x, double y){ 
            X_values.push_back({x,1});
            y_values.push_back(y);
        }
        //adding a single value 
        void add_value(double x, double y) 
        {
            X_values.push_back({x,1});
            y_values.push_back(y);
        }

        pair<double, double> return_constants() { //returns A and C where A,C are used as y = Ax + C
            //if fit_line() gives -1, return {0, y_value[0]} cause we have one point (maybe repeated many times)
            //note this behaviour in readme
            if(X_values.size() == 0){
                return {0,0}; // No data given — return default line y = 0
            }
            int fit_line_output = fit_line();
            if(fit_line_output == -1){
                return {0, y_values[0]};
            } else if(fit_line_output == 1){
                return {A,C};
            }
        }

    private:
        vector<pair<double,int>>X_values;
        vector<double>y_values;
        double A;
        double C;
        //where line is y= Ax+ C
        int fit_line()
        { //return -1 if determinant is 0, else 1
            double x_xt[2][2] = {{0,0} , {0,0}};
            for(int i = 0; i<X_values.size(); i++)
            {
                x_xt[0][0] += X_values[i].first*X_values[i].first;
                x_xt[0][1] += X_values[i].first;
            }
            x_xt[1][0] = x_xt[0][1]; //here its the same
            x_xt[1][1] = X_values.size(); //its [1,1,1..]*[1,1,1..]T

            //inverting x_xt
            double determinant = x_xt[0][0]*x_xt[1][1] - x_xt[1][0]*x_xt[0][1];
            if(determinant == 0){return -1;}

            double x_xt_i[2][2] = {{0,0} , {0,0}};
            x_xt_i[0][0] = x_xt[1][1]/determinant;
            x_xt_i[1][1] = x_xt[0][0]/determinant;
            x_xt_i[0][1] = -1 * x_xt[0][1]/determinant;
            x_xt_i[1][0] = -1 * x_xt[1][0]/determinant;

            //multiplying X_valuesT and y
            double xt_y [2][1] = { {0}, {0}};
            for(int i = 0; i<X_values.size(); i++)
            {//X_values and y have the same size
                xt_y[0][0] += X_values[i].first*y_values[i];
                xt_y[1][0] += y_values[i];
            }

            //finally, multiplying xt_y and inverted x_xt and modifying A and C
            A = x_xt_i[0][0]*xt_y[0][0] + x_xt_i[0][1]*xt_y[1][0];
            C = x_xt_i[1][0]*xt_y[0][0] + x_xt_i[1][1]*xt_y[1][0];
            return 1;
        }
        
};