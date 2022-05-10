typedef long long ll;

void solve(ll a_unit, ll a_cost, ll b_unit, ll b_cost, ll target) { //b가 가성비
    ll lcmAB = lcm(a_unit, b_unit);
    ll minimum_amount = 1e18 + 1;

    int a_bundle = 0;
    while (a_unit * a_bundle < lcmAB) {
        if (target <= a_unit * a_bundle) {
            if (a_cost * a_bundle < minimum_amount)
                minimum_amount = a_cost * a_bundle;
            break;
        }
        ll remainder = target - a_unit * a_bundle;
        ll b_bundle = (remainder - 1) / b_unit + 1;

        ll cost = a_cost * a_bundle + b_cost * b_bundle;
        if (cost < minimum_amount)
            minimum_amount = cost;

        a_bundle++;
    }
    cout << minimum_amount;
}

int main() {
    ll target, a_unit, a_cost, b_unit, b_cost;
    cin >> target >> a_unit >> a_cost >> b_unit >> b_cost;

    if (b_cost * a_unit < a_cost * b_unit)
        solve(a_unit, a_cost, b_unit, b_cost, target);
    else
        solve(b_unit, b_cost, a_unit, a_cost, target);
}