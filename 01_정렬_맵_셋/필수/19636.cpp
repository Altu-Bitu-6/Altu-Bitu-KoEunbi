#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void cal(map<string, int> &diet){
    int kcal;
    diet["after_W"] = diet["before_W"];
    
    for(int i=0; i<diet["D"]; i++){
        kcal = diet["after_I"] - (diet["BMR"]+diet["A"]);
        diet["after_W"] += kcal;
        if(diet["BMR_change"]==1 && abs(kcal)>diet["T"]) 
            diet["BMR"] += (int)floor((double)kcal/2.0);

    }

    if(diet["after_W"]<=0 || diet["BMR"] <= 0){
        cout << "Danger Diet";
    }else{
        cout << diet["after_W"] << " " << diet["BMR"];
        
        if(diet["BMR_change"]==1){
            if(diet["before_I"] > diet["BMR"])
                cout <<" YOYO";
            else 
                cout << " NO";
        }
    }

}

int main(){
    map<string, int> diet;

    cin >> diet["before_W"] >> diet["before_I"] >> diet["T"];
    cin >> diet["D"] >> diet["after_I"] >> diet["A"];
    diet["BMR"] = diet["before_I"];
    diet["after_W"] = diet["before_W"];

    diet["BMR_change"] = 0;
    cal(diet);
    cout << "\n";
    diet["BMR_change"] = 1;
    cal(diet);
    

    return 0;
}