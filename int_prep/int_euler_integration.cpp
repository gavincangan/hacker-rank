/*
* t_end - the target time, t, to which to integrate the system to
* x0 - the initial value of x(t) at t = 0
* x_d0 - the initial value of x_d(t) at t = 0, where x_d is the time derivative of x(t)
* dt - time step in seconds used to integrate the system
*/
float integrateFunction(float t_end, float x0, float x_d0, float dt) {
    /*
     * Write your code here.
     */
        float t_now = 0.0F;
        float x_now = x0, dx=x_d0, ddx=0.0;
        float F = 0.0, m=4.0, k=4.0;
        
        F = (dx < 0)?0.5:-0.5;
        cout<<x_now<<"\t"<<dx<<"\t"<<t_now<<endl;
        while(t_end - t_now >= dt )
        {
                ddx = -x_now + (1/m)*F;

                x_now += dx * dt;
                t_now += dt;
                
                dx += ddx * dt;
                F = (dx < 0)?0.5:-0.5;                
                cout<<x_now<<"\t"<<dx<<"\t"<<t_now<<endl;
        }
        return x_now;
        
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    float t_end;
    cin >> t_end;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    float x0;
    cin >> x0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    float x_d0;
    cin >> x_d0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    float dt;
    cin >> dt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    float res = integrateFunction(t_end, x0, x_d0, dt);

    fout << setprecision(5) << fixed << res << "\n";

    fout.close();

    return 0;
}
