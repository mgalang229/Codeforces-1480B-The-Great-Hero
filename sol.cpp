#include <bits/stdc++.h>

using namespace std;

long long max(long long a, long long b) {
	return (a > b ? a : b);
}

int main() {                            
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
 	cin >> tt;
 	while (tt--) {
 		long long attack_power_of_hero, health_of_hero, n;
 		cin >> attack_power_of_hero >> health_of_hero >> n;
 		vector<long long> attack_power_of_monster(n), health_of_monster(n);
 		for (int i = 0; i < n; i++) {
 			cin >> attack_power_of_monster[i];
 		}
 		for (int i = 0; i < n; i++) {
 			cin >> health_of_monster[i];
 		}
 		// create a vector pair to store the attack power of every monster together with its corresponding initial health
 		vector<pair<long long, long long>> v;
 		for (int i = 0; i < n; i++) {
 			v.emplace_back(make_pair(attack_power_of_monster[i], health_of_monster[i]));
 		}
 		// sort the vector pair in nondecreasing order in terms of attack power to attain efficiency
 		sort(v.begin(), v.end());
 		// re-arrange the attack power of a monster with its health in the new order created
 		for (int i = 0; i < n; i++) {
 			attack_power_of_monster[i] = v[i].first;
 			health_of_monster[i] = v[i].second;
 		}
		for (int i = 0; i < n; i++) {
			// create a while-loop for every battle of the hero and a specific monster
			// end the loop if one of them has health that is less than or equal to 0
			while (health_of_hero > 0 && health_of_monster[i] > 0) {
				// subtract the attack power of the hero from the health of the monster
			  health_of_monster[i] = max(0, health_of_monster[i] - attack_power_of_hero);
			  // simultaneously, subtract the attack of a monster from the health of the hero
			  health_of_hero = max(0, health_of_hero - attack_power_of_monster[i]);
			}
		}
		// check if all the monsters are killed even if the hero is dead as well
		bool checker = true;
		for (int i = 0; i < n; i++) {
			if (health_of_monster[i] > 0) {
				checker = false;
				break;
			}
		}                              
   	cout << (checker ? "YES" : "NO") << '\n';
 	}
  return 0;
}      
