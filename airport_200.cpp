#include<iostream>
#include<string>
using namespace std;

int main ()
{
    int n, k, q;
    cin>>n>>k;

    string V3Landing[200];
    string V2Takingoff[200];
    string BOUND[k];

    string AP_V1[200];
    for (int i=0; i<n; i++)
        cin>>AP_V1[i];

    cin>>q;
    string answer[q];
    int x=0;

    string order;
    string ID;
    int ID2;
    for (int i=0; i<q; i++)
    {
        cin>>order;
        if (order=="TAKE-OFF")
        {
            cin>>ID;
            for (int j=0; j<k; j++)
            {
                if (V2Takingoff[j]==ID)
                {    
                    answer[x]="YOU ARE TAKING OFF";
                    x++;
                    break;
                }
                else if (V3Landing[j]==ID)
                {    
                    answer[x]="YOU ARE LANDING NOW";
                    x++;
                    break;
                }
                else if (AP_V1[j]==ID)
                {
                    for (int h=0; h<k; h++)
                    {
                        if (BOUND[h]=="")
                        {
                            //V2Takingoff[h]=ID;
                            AP_V1[j]="";
                            BOUND[h]=ID;
                            for (int z=0; z<k; z++)
                            {   
                                if (V2Takingoff[z]=="")
                                {
                                    V2Takingoff[z]=ID;
                                    break;
                                }
                            }
                            break;
                        }
                        else if (h==k-1)
                        {
                            answer[x]="NO FREE BOUND";
                            x++;
                            //cout<<"NO FREE BOUND\n";
                        }
                    }
                    break;
                }
                else if (j==k-1)
                {
                    answer[x]="YOU ARE NOT HERE";
                    x++;
                    //cout<<"YOU ARE NOT HERE\n";
                }
            }
            continue;
        }
        if (order=="LANDING")
        {
            cin>>ID;
            for (int j=0; j<k; j++)
            {
                if (V2Takingoff[j]==ID)
                {
                    answer[x]="YOU ARE TAKING OFF";
                    x++;
                    break;
                }
                else if (V3Landing[j]==ID)
                {
                    answer[x]="YOU ARE LANDING NOW";
                    x++;
                    break;
                }
                else if (AP_V1[j]==ID)
                {
                    answer[x]="YOU ARE HERE";
                    x++;
                    //cout<<"YOU ARE HERE\n";
                    break;
                }
                else if (j==k-1)
                {
                    for (int h=(k-1); h>=0; h--)
                    {
                        if (BOUND[h]=="")
                        {   
                            BOUND[h]=ID;
                            // V3Landing[h]=ID;
                            for (int z=0; z<k; z++)
                            {   
                                if (V3Landing[z]=="")
                                {
                                    V3Landing[z]=ID;
                                    break;
                                }
                            }
                            break;
                        }
                        else if (h==0)
                        {
                            answer[x]="NO FREE BOUND";
                            x++;
                            //cout<<"NO FREE BOUND\n";
                        }
                    }
                    break;
                }
            }
            continue;
        }
        if (order=="PLANE-STATUS")
        {
            cin>>ID;
            for (int j=0; j<n+k; j++)
            {
                if (ID==V2Takingoff[j])
                {
                    answer[x]="2";
                    x++;
                    //cout<<"2\n";
                    break;
                }
                else if (ID==V3Landing[j])
                {
                    answer[x]="3";
                    x++;
                    //cout<<"3\n";
                    break;
                }
                else if (ID==AP_V1[j])
                {
                    answer[x]="1";
                    x++;
                    //cout<<"1\n";
                    break;
                }
                else if (j==n+k-1)
                {
                    answer[x]="4";
                    x++;
                    //cout<<"4\n";
                }
            }
            continue;
        } 
        if (order=="BAND-STATUS")
        {
            cin>>ID2;
            if (BOUND[ID2-1]=="")
            {
                answer[x]="FREE";
                x++;
                //cout<<"FREE\n";
            }
            else
            { 
                answer[x]=BOUND[ID2-1];
                x++;
                //cout<<BOUND[ID2-1]<<"\n";
            }
        }
    } 
    for (int y=0; y<x; y++)
            cout<<answer[y]<<"\n";
}