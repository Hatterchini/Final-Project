// Final Project cppWorking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono> //For wait commands https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program//
#include <cmath>
#include <Windows.h>
#include <stdlib.h>// Clear commands
#include <limits>
// More System Commands https://stackoverflow.com/questions/21257544/c-wait-for-user-input

//https://github.com/ArashPartow/exprtk?tab=readme-ov-file#readme Input taking//
// Source for The picture of Ari I used as Numin https://class-of-nine.fandom.com/wiki/Ari converted with https://manytools.org/hacker-tools/convert-images-to-ascii-art/go/

using namespace std;
double sinfunc(double x, double a, double b, double c, double d) {
    return a*sin(b*x)+c;
};
double cosfunc(double x, double a, double b, double c, double d) {
    return a * cos(b * x) + c;
};
double tanfunc(double x, double a, double b, double c, double d) {
    return a * tan(b * x) + c;
};
double threevariables(double x, double a, double b, double c, double d) {
    return a*(x * x * x) + b*(x + x) + c*(x) +d;
}


double legarde(double interpolatevalue, double vecterfdefine[], double vectorfvalues[], int length) {
    double interpolate_value = 0;
    for (int i = 1; i < (length + 1); i++) {
        double legard = 1;

        for (int j = 1; j < (length + 1); j++) {
            if (j != i) {
                legard = legard * ((interpolatevalue - vecterfdefine[j])) / (vecterfdefine[i] - vecterfdefine[j]);
            }
        }
        interpolate_value = interpolate_value + (legard * vectorfvalues[i]);
    }
    return interpolate_value;
};
double TrapsruleFunction(double (*func)(double,double,double,double,double),double head,double foot, int subdivisions, double a, double b, double c, double d) {
    double summation = 0;
    double h = (foot - head) / subdivisions;
    for (int i = 1; i < (subdivisions); i++) {
        summation += func(head+ (i * h), a, b, c, d);
        //cout << summation << endl;
    }
    double total = (h/2)*(func(foot,a,b,c,d) + (2*summation)+ func(head,a, b, c, d));
    return total;
}
double simpsonsrulefunction(double (*func)(double,double,double,double,double), double head, double foot, int subdivisions, double a, double b, double c, double d) {
    double h = (foot - head) / subdivisions; 
    double sum_odd = 0.0;  
    double sum_even = 0.0; 

    // Loop over odd-indexed points (4x multiplier)
    for (int i = 1; i < subdivisions; i += 2) {
        sum_odd += func(head + i * h,a, b, c, d);
    }

    // Loop over even-indexed points (2x multiplier)
    for (int i = 2; i < subdivisions; i += 2) {
        sum_even += func(head + i * h, a, b, c, d);
    }

    // Simpson's Rule formula
    double total = (h / 3.0) * (func(head, a, b, c, d) + func(foot, a, b, c, d) + 4.0 * sum_odd + 2.0 * sum_even);
    if (head > foot) {
        total = -total;
    }
    return total;
}
double Trapsruledata(double x[], double y[], double stepside, int length) {
    double summation = 0.0;
    double stepvalue = x[0];

    while (stepvalue < x[length - 1]) {
        double interpolatedValue = legarde(stepvalue, x, y, length);
        summation += interpolatedValue;
        stepvalue += stepside;
    }

    return (y[0] + 2 * summation + y[length - 1]) * (stepside / 2.0);
}
double Simpsonsruledata(double x[], double y[], double stepside, int length) {
    if ((length - 1) % 2 != 0) {
        cout << "listen buddy, Don't mess with me the data's wrong.\n";
        return -1;
    }

    double summationOdd = 0.0;
    double summationEven = 0.0;

    double stepvalue = x[0];
    for (int i = 1; i < length - 1; i++) {
        stepvalue += stepside;
        double value = (x[i] == stepvalue) ? y[i] : legarde(stepvalue, x, y, length);

        if (i % 2 == 0) {
            summationEven += value;
        }
        else {
            summationOdd += value;
        }
    }

    return (stepside / 3.0) * (y[0] + 4 * summationOdd + 2 * summationEven + y[length - 1]);
}
int logo(){
    // Tool used for Ascii art https://ascii.today/ //
    cout << "    ______      __          ____                                            __           __\n";
    Sleep(300);
    cout << "   / ____/___ _/ /____     /  _/___  _________  _________  ___  _________ _/ /____  ____/ /\n";
    Sleep(200);
    cout << "  / /_  / __ `/ __/ _ \\    / // __ \\/ ___/ __ \\/ ___/ __ \\/ _ \\/ ___/ __ `/ __/ _ \\/ __  / \n";
    Sleep(150);
    cout << " / __/ / /_/ / /_/  __/  _/ // / / / /__/ /_/ / /  / /_/ /  __/ /  / /_/ / /_/  __/ /_/ /  \n";
    Sleep(125);
    cout << "/_/    \\__,_/\\__/\\___/  /___/_/ /_/\\___/\\____/_/  / .___/\\___/_/   \\__,_/\\__/\\___/\\__,_/   \n";
    Sleep(100);
    cout << "                                                 /_/                                      \n";
    cout << "\n\n\n";

        cout << "    _   __                          _            __   ____      __                        __  _                  \n";
        Sleep(75);
        cout << "   / | / /_  ______ ___  ___  _____(_)________ _/ /  /  _/___  / /____  ____ __________ _/ /_(_)___  ____        \n";
        Sleep(75);
        cout << "  /  |/ / / / / __ `__ \\/ _ \\/ ___/ / ___/ __ `/ /   / // __ \\/ __/ _ \\/ __ `/ ___/ __ `/ __/ / __ \\/ __ \\       \n";
        Sleep(75);
        cout << " / /|  / /_/ / / / / / /  __/ /  / / /__/ /_/ / /  _/ // / / / /_/  __/ /_/ / /  / /_/ / /_/ / /_/ / / / /       \n";
        Sleep(75);
        cout << "/_/ |_/_\\__,_/_/ /_/ /_/\\___/_/  /_/\\___/\\__,_/_/  /___/_/ /_/\\__/\\___/\\__, /_/   \\__,_/\\__/_/\\____/_/ /_/        \n";
        Sleep(75);
        cout << "                                                                     /____/                                      \n";
        system("pause");
        system("cls");
        return 0;

}
void numin() {
    cout << "                                    .,*,..                                      " << endl;
    cout << "                              (%%%%%%%%%%%%%%&&#(                               " << endl;
    cout << "                          ,%%%%%%%%%%%%%%%%%&%%%&%#%(                           " << endl;
    cout << "                        %%#%%%%%%%%%%%%%%%%%%%%%%%%%%%%,                        " << endl;
    cout << "                      %%%%%%###(%%%%%%%%%%%%%%%%%%%%%%%%%.                      " << endl;
    cout << "                     %%%%%%%%%%(#%%###*##%%%#%%(#//%%%(%%(#                     " << endl;
    cout << "                    ,%%%%%%%%%%%&%%%%%(%%%##%%%%%%%%%%%%%%%%                    " << endl;
    cout << "                    .%%%%%%%%%%&%%%%%%%%%%%%%(%%%%%%%&%%%%%##*                  " << endl;
    cout << "                     %%%&&&&&%&%%%%%%%%%%%&*.,%%%&%%&&%%&%%%,(*                 " << endl;
    cout << "                     (%%&&&&&&&%%%%&%&&&%.   ,%%&&%%&##%%%%%* &                 " << endl;
    cout << "                     /%&&%%%%&&%#%&&&(.  . .  .&/&&&(,.%%#&&  &                 " << endl;
    cout << "                    ,(&%%%(%%*&%%&%,.%@@@@&,  . #(..  .%%&&* /*                 " << endl;
    cout << "                  #/.&&&%%%%.,,#&&.., /(//       (%%,#%%&&/*                    " << endl;
    cout << "              ,%   (&%&&&&%&*,,.,&(    .         .* .(&&%                       " << endl;
    cout << "               #/#&&&&%&&%%&&&&&*,(             .    &&%#                       " << endl;
    cout << "                  &%%%%%%%%&&&&&&&,.               .*&&&(,                      " << endl;
    cout << "             *   %&%&&%%%%%&&&%&&%&,*,          . /&&%%&/                       " << endl;
    cout << "                 /&&&&&%((%%&&%%&&&,,,,,,,.   .&&%%&&#(&( *                     " << endl;
    cout << "                   %&,#%  %%%&&%&(%%,,,,,,,,%&@&%#&&&%(&%                       " << endl;
    cout << "                    #   .   &%&,/%%%,......,,*@&&/ &&. #%                       " << endl;
    cout << "                          ,((%((((/.............((//#.                          " << endl;
    cout << "                    ,///********////* .  ...  .//(//*****//,                    " << endl;
    cout << "                  ,(/**************////***//////*********/***                   " << endl;
    cout << "                  (/****///*******//*******//***********//**/                   " << endl;
    cout << "                  (//****///*****(..NOW.,*,,,***/##(*****//****,                " << endl;
    cout << "                  ///*****/(****/*.*/./.,*(//,***####/**/////,                   " << endl;

}
void legard() {
        cout << "$$\\                                                                           " << endl;
        cout << "$$ |                                                                          " << endl;
        cout << "$$ |      $$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$\\  $$$$$$$\\   $$$$$$\\   $$$$$$\\  " << endl;
        cout << "$$ |     $$  __$$\\ $$  __$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ " << endl;
        cout << "$$ |     $$$$$$$$ |$$ /  $$ |$$ |  \\__|$$$$$$$ |$$ |  $$ |$$ /  $$ |$$$$$$$$ |" << endl;
        cout << "$$ |     $$   ____|$$ |  $$ |$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$   ____|" << endl;
        cout << "$$$$$$$$\\\\$$$$$$$\\ \\$$$$$$$ |$$ |     \\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$$\\ " << endl;
        cout << "\\________|\\_______| \\____$$ |\\__|      \\_______|\\__|  \\__| \\____$$ | \\_______|" << endl;
        cout << "                   $$\\   $$ |                             $$\\   $$ |          " << endl;
        cout << "                   \\$$$$$$  |                             \\$$$$$$  |          " << endl;
        cout << "                    \\______/                               \\______/           " << endl;


}
void riemann() {
        cout << R"(
$$$$$$$\  $$\                                                                                                         
$$  __$$\ \__|                                                                                                        
$$ |  $$ |$$\  $$$$$$\  $$$$$$\$$$$\   $$$$$$\  $$$$$$$\  $$$$$$$\         $$$$$$$\ $$\   $$\ $$$$$$\$$$$\   $$$$$$$\ 
$$$$$$$  |$$ |$$  __$$\ $$  _$$  _$$\  \____$$\ $$  __$$\ $$  __$$\       $$  _____|$$ |  $$ |$$  _$$  _$$\ $$  _____|
$$  __$$< $$ |$$$$$$$$ |$$ / $$ / $$ | $$$$$$$ |$$ |  $$ |$$ |  $$ |      \$$$$$$\  $$ |  $$ |$$ / $$ / $$ |\$$$$$$\  
$$ |  $$ |$$ |$$   ____|$$ | $$ | $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |       \____$$\ $$ |  $$ |$$ | $$ | $$ | \____$$\ 
$$ |  $$ |$$ |\$$$$$$$\ $$ | $$ | $$ |\$$$$$$$ |$$ |  $$ |$$ |  $$ |      $$$$$$$  |\$$$$$$  |$$ | $$ | $$ |$$$$$$$  |
\__|  \__|\__| \_______|\__| \__| \__| \_______|\__|  \__|\__|  \__|      \_______/  \______/ \__| \__| \__|\_______/ 
    )" << endl;
    
}
int main()
{
    logo();
    int finale = 1;
    int null;
    while (finale == 1) {
        int choiceofvalues = 0;
        int chioceofsolution;
        int sizeofarray = 0;
        int function;
        bool repeat = true;

        cout << "Hello!";
        Sleep(100);
        cout << "\n I'm NUMIN.";
        numin();

        cout << "\nshort for Numerical Integration!\n I am here to help you Figure out your integration\n";
        system("pause"
        );
        system("cls");
        cout << "\n I am here to help you integrate your functions.\n";
        Sleep(100);
        while (repeat == true) {
            cout << "\n Currently I support 2 ways to accept data and 2 ways to interpert that data!";
            cout << "\n lets start at the beginning, How would you  like me to calculate data";
            cout << "\n 1: using a table of values";
            cout << "\n 2: using a function!\n";
            cout << "If you'd Like to know more about my creation Please type 3";
            cin >> choiceofvalues;

            if (choiceofvalues == 1 || choiceofvalues == 2||choiceofvalues == 3) {
                repeat = false;
            }
            else {
                cout << "This is an invalid input please try again";
                cin.clear();
                //https://stackoverflow.com/questions/20745938/why-does-a-program-become-broken-when-a-character-is-input-when-prompted-to-inpu/20746249#20746249
                cin.ignore();
            }
        }
        system("cls");
        repeat = true;
        cout << "Great! Now i know what we are working with";
        if (choiceofvalues == 1 || choiceofvalues == 2) {
            cout << "Now lets pick the method we want to integrate. Do you think we should use \n 1: The trapezoidal Rule(My favorite) \n 2:simpsons rule!\n";
            cin >> chioceofsolution;
        }
        if (choiceofvalues == 1) {
            cout << "Awesome now let me get some data from you!\n";
            cout << "How many data points do you have for me to analyze?";
            cin >> sizeofarray;

            double* xvalues = new double[sizeofarray];
            double* yvalues = new double[sizeofarray];
            double stepvalue;

            cout << "Great! Now please start listing out the x values and hitting enter. \nI will only stop counting when you've reached the number you told me!\n";
            for (int i = 0; i < sizeofarray; i++) {
                cin >> xvalues[i];
            }

            cout << "Now would you kindly please do the same thing, but with the Y values?";
            for (int i = 0; i < sizeofarray; i++) {
                cin >> yvalues[i];
            }

            cout << "Thank you! Now please pick the step value for your data!\n";
            cin >> stepvalue;

            cout << "Thanks, this should be enough for me to calculate your integral! Please give me a moment!";
            cout << "...";
            Sleep(100);
            if (chioceofsolution == 1) {
                double solution = Trapsruledata(xvalues, yvalues, stepvalue, sizeofarray);
                cout << "Beep boop... Your number is ready. Your integral is: " << solution;
            }
            if (chioceofsolution == 2) {
                double solution = Simpsonsruledata(xvalues, yvalues, stepvalue, sizeofarray);
                cout << "Beep boop... Your number is ready. Your integral is: " << solution;
            }
            delete[] xvalues;
            delete[] yvalues;
        }
        if (choiceofvalues == 2) {
            double a = 0;
            double b = 0;
            double c = 0;
            double d = 0;
            int subdivisions = 0;
            double upperbound = 0;
            double lowerbound = 0;
            cout << "Checkpoint 1 Reached!";
            while (repeat == true) {
                cout << "Just a precurser\n Function input is not completely supported due to the way parses work, But I can Handle a certain set of programs \n";
                cout << "Here is a quick list of all the functions that I do support right now\n";
                cout << "1: sin functions such as: \n \t A*sin(B)+C" << endl;
                cout << "2: cosine functions such as: \n \t A*cos(B)+C" << endl;
                cout << "3: tangent functions such as: \n \t A*tan(B)+C" << endl;
                cout << "4: 3 variable Curved functions: \n \t a(x*x*x) + b(x*x) c*x + d" << endl;
                cout << "\t \t Please just let me know what I can do to help you find the solutions to these problems" << endl;
                cin >> function;
                cin.clear();
                cin.ignore();
                if (function <= 4 || function > 0) {
                    repeat = false;
                }
                else {
                    cout << "This is an invalid input please try again";
                }
            }
            repeat = true;
            if (function == 1) {
                cout << "Its a pleasure to use the sin function with you.\n if I'm allowed to ask what is your A value? \n";
                while (repeat == true) {
                    cin >> a;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                Sleep(100);
                system("cls");
                repeat = true;
                cout << "Alright I get that, Now whats the value of B";
                while (repeat == true) {
                    cin >> b;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                repeat = true;
                Sleep(100);
                system("cls");
                cout << "And For C?";
                while (repeat == true) {
                    cin >> c;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                Sleep(100);
                system("cls");
                cout << "And the amount of subdivisions!";
                cin >> subdivisions;
                cout << "Alright I seem to have that all Figured out, I just need 2 more things from  you \n The upper bound \n the lower bound\n Please input them respectively! \n";
                cin >> upperbound;
                cout << endl;
                cin >> lowerbound;
                cout << "That should be everything Please standby for your code!";
                Sleep(200);
                if (chioceofsolution == 1) {
                    cout << "Alright we Have your Function! \n Make sure to have a fantastic day! \n Your result is " << TrapsruleFunction(sinfunc, upperbound, lowerbound, subdivisions, a, b, c, d);
                }
            }
            if (function == 2) {
                cout << "Its a pleasure to use the cosine function with you.\n if I'm allowed to ask what is your A value? \n";
                while (repeat == true) {
                    cin >> a;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                Sleep(100);
                system("cls");
                repeat = true;
                cout << "Alright I get that, Now whats the value of B";
                while (repeat == true) {
                    cin >> b;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                repeat = true;
                Sleep(100);
                system("cls");
                cout << "And For C?";
                while (repeat == true) {
                    cin >> c;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                Sleep(100);
                system("cls");
                cout << "And the amount of subdivisions!";
                cin >> subdivisions;
                cout << "Alright I seem to have that all Figured out, I just need 2 more things from  you \n The upper bound \n the lower bound\n Please input them respectively! \n";
                cin >> upperbound;
                cout << endl;
                cin >> lowerbound;
                cout << "That should be everything Please standby for your code!";
                Sleep(200);
                if (chioceofsolution == 1) {
                    cout << "Alright we Have your Function! \n Make sure to have a fantastic day! \n Your result is " << TrapsruleFunction(cosfunc, upperbound, lowerbound, subdivisions, a, b, c, d);
                }
            }
            if (function == 3) {
                cout << "Its a pleasure to use the sin function with you.\n if I'm allowed to ask what is your A value? \n";
                while (repeat == true) {
                    cin >> a;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                Sleep(100);
                system("cls");
                repeat = true;
                cout << "Alright I get that, Now whats the value of B";
                while (repeat == true) {
                    cin >> b;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                repeat = true;
                Sleep(100);
                system("cls");
                cout << "And For C?";
                while (repeat == true) {
                    cin >> c;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                Sleep(100);
                system("cls");
                cout << "And the amount of subdivisions!";
                cin >> subdivisions;
                cout << "Alright I seem to have that all Figured out, I just need 2 more things from  you \n The upper bound \n the lower bound\n Please input them respectively! \n";
                cin >> upperbound;
                cout << endl;
                cin >> lowerbound;
                cout << "That should be everything Please standby for your code!";
                Sleep(200);
                if (chioceofsolution == 1) {
                    cout << "Alright we Have your Function! \n Make sure to have a fantastic day! \n Your result is " << TrapsruleFunction(tanfunc, upperbound, lowerbound, subdivisions, a, b, c, d);
                }
            }
            if (function == 4) {
                cout << "Its a pleasure to use the sin function with you.\n if I'm allowed to ask what is your A value? \n";
                while (repeat == true) {
                    cin >> a;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                Sleep(100);
                system("cls");
                repeat = true;
                cout << "Alright I get that, Now whats the value of B";
                while (repeat == true) {
                    cin >> b;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                repeat = true;
                Sleep(100);
                system("cls");
                cout << "And For C?";
                while (repeat == true) {
                    cin >> c;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                cout << "And Finally D";
                while (repeat == true) {
                    cin >> d;
                    cin.clear();
                    cin.ignore();
                    if (function <= 4 || function > 0) {
                        repeat = false;
                    }
                    else {
                        cout << "This is an invalid input please try again";
                    }
                }
                Sleep(100);
                system("cls");
                cout << "And the amount of subdivisions!";
                cin >> subdivisions;
                cout << "Alright I seem to have that all Figured out, I just need 2 more things from  you \n The upper bound \n the lower bound\n Please input them respectively! \n";
                cin >> upperbound;
                cout << endl;
                cin >> lowerbound;
                cout << "That should be everything Please standby for your code!";
                Sleep(200);
                if (chioceofsolution == 1) {
                    cout << "Alright we Have your Function! \n Make sure to have a fantastic day! \n Your result is " << TrapsruleFunction(tanfunc, upperbound, lowerbound, subdivisions, a, b, c, d);
                }
            }
            return 0;
        };
        if (choiceofvalues == 3) {
            cout << "                                                                                 " << endl;
            cout << "                                                                                 " << endl;
            cout << "        GGGGGGGGGGGGG                                   lllllll                  " << endl;
            cout << "     GGG::::::::::::G                                   l:::::l                  " << endl;
            cout << "   GG:::::::::::::::G                                   l:::::l                  " << endl;
            cout << "  G:::::GGGGGGGG::::G                                   l:::::l                  " << endl;
            cout << " G:::::G       GGGGGG   ooooooooooo     aaaaaaaaaaaaa    l::::l     ssssssssss   " << endl;
            cout << "G:::::G               oo:::::::::::oo   a::::::::::::a   l::::l   ss::::::::::s  " << endl;
            cout << "G:::::G              o:::::::::::::::o  aaaaaaaaa:::::a  l::::l ss:::::::::::::s " << endl;
            cout << "G:::::G    GGGGGGGGGGo:::::ooooo:::::o           a::::a  l::::l s::::::ssss:::::s" << endl;
            cout << "G:::::G    G::::::::Go::::o     o::::o    aaaaaaa:::::a  l::::l  s:::::s  ssssss " << endl;
            cout << "G:::::G    GGGGG::::Go::::o     o::::o  aa::::::::::::a  l::::l    s::::::s      " << endl;
            cout << "G:::::G        G::::Go::::o     o::::o a::::aaaa::::::a  l::::l       s::::::s   " << endl;
            cout << " G:::::G       G::::Go::::o     o::::oa::::a    a:::::a  l::::l ssssss   s:::::s " << endl;
            cout << "  G:::::GGGGGGGG::::Go:::::ooooo:::::oa::::a    a:::::a l::::::ls:::::ssss::::::s" << endl;
            cout << "   GG:::::::::::::::Go:::::::::::::::oa:::::aaaa::::::a l::::::ls::::::::::::::s " << endl;
            cout << "     GGG::::::GGG:::G oo:::::::::::oo  a::::::::::aa:::al::::::l s:::::::::::ss  " << endl;
            cout << "        GGGGGG   GGGG   ooooooooooo     aaaaaaaaaa  aaaallllllll  sssssssssss    " << endl;
            cout << "\n \n So the Main thought that I had with Numin Was Why? \n What will Numin accomplish.\n Why would you make a program that does something you want it to do by hand. \n Well the point is to not do this kinda stuff by hand so we can focus on other stuff\n";
            cout << "In my opinion there is nothing worse than wasting your brain power on something that can be automated \n";
            cout << "And thus Numin Was born\n Mostly cause I hate doing any form of integration\n";
            cout << "As for why I chose to gave Numin a personality.\n Well Its very artistic and if We can't make our code with a little bit of ourselves in it. Why even bother?\n";
            system("pause");
            system("cls");
            cout << "    __  __             ___ " << endl;
            cout << "   / / / /___ _      _/__ \\" << endl;
            cout << "  / /_/ / __ \\ | /| / // _/" << endl;
            cout << " / __  / /_/ / |/ |/ //_/  " << endl;
            cout << "/_/ /_/\\____/|__/|__/(_)   " << endl;
            cout << "Numin Uses a couple different algorithms to do her job.\n Legrange's formula(Although I call it Legardes formula for Pop culture reasons)\n Riemann sums(with trapzoids) \n Simpson's Rule\n";
            system("pause");
            system("cls");
            legard();
            cout << "There isn't really much to talk about with Legranges formula overall. However it plays a key role in this program \n It is worthy to note that it is a summation of points following the general form of \n (x-x1)(x-x2)*y0\n ---------------- \n (x0-x1)*(x0-x2)\n";
            system("pause");
            riemann();
            cout << "The Riemann sum was much more intresting for me to work on. Mine was a modified riemanns sum in the shape of trapazoids \n Given enough small trapazoids you can fill even a true curve.\n";
            cout << "Thats the Fundamentals of integration calculus";
            cout << "This program uses the datapoints its given to create those small rectangles and then when it doesn't have the right steps. It just uses Legranges method To Find them";
        }
        cout << "its was a pleasuring working with you but if you'd like to continue working with me, Please Type 1\n if not please type anything Else ";
        cin >> finale;

        if (finale != 1) {
            cout << "Thank you so much for Using me to help with your code\n ";
            cout << "And don't forget, The time is now \n";
            cout << "       ,--.-----.--." << endl;
            cout << "       |--|-----|--|" << endl;
            cout << "       |--|     |--|" << endl;
            cout << "       |  |-----|  |" << endl;
            cout << "     __|--|     |--|__" << endl;
            cout << "    /  |  |-----|  |  \\" << endl;
            cout << "   /   \\__|-----|__/   \\" << endl;
            cout << "  /   ______---______   \\/\\" << endl;
            cout << " /   /               \\   \\/" << endl;
            cout << "{   /                 \\   }" << endl;
            cout << "|  {       Now         }  |-," << endl;
            cout << "|  |                   |  | |" << endl;
            cout << "|  {                   }  |-'" << endl;
            cout << "{   \\                 /   }" << endl;
            cout << " \\   `------___------'   /\\" << endl;
            cout << "  \\     __|-----|__     /\\/" << endl;
            cout << "   \\   /  |-----|  \\   /" << endl;
            cout << "    \\  |--|     |--|  /" << endl;
            cout << "     --|  |-----|  |--" << endl;
            cout << "       |--|     |--|" << endl;
            cout << "       |--|-----|--|" << endl;
            cout << "       `--'-----`--'" << endl;
            Sleep(1000);
        }

    }
}