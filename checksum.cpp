#include <bits/stdc++.h>
using namespace std;

// Function to find the One's complement
// of the given binary string
string Ones_complement(string data){

	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '0')
			data[i] = '1';
		else
			data[i] = '0';
	}

	return data;
}

string checkSum(string data, int block_size){

	int n = data.length();
	if (n % block_size != 0) {
		int pad_size = block_size - (n % block_size);
		for (int i = 0; i < pad_size; i++) {
			data = '0' + data;
		}
	}

	string result = "";


	for (int i = 0; i < block_size; i++) {
		result += data[i];
	}

	for (int i = block_size; i < n; i += block_size) {

		string next_block = "";

		for (int j = i; j < i + block_size; j++) {
			next_block += data[j];
		}

		string additions = "";
		int sum = 0, carry = 0;

		for (int k = block_size - 1; k >= 0; k--) {
			sum += (next_block[k] - '0')
				+ (result[k] - '0');
			carry = sum / 2;
			if (sum == 0) {
				additions = '0' + additions;
				sum = carry;
			}
			else if (sum == 1) {
				additions = '1' + additions;
				sum = carry;
			}
			else if (sum == 2) {
				additions = '0' + additions;
				sum = carry;
			}
			else {
				additions = '1' + additions;
				sum = carry;
			}
		}

		string final = "";

		if (carry == 1) {
			for (int l = additions.length() - 1; l >= 0;
				l--) {
				if (carry == 0) {
					final = additions[l] + final;
				}
				else if (((additions[l] - '0') + carry) % 2
						== 0) {
					final = "0" + final;
					carry = 1;
				}
				else {
					final = "1" + final;
					carry = 0;
				}
			}

			result = final;
		}
		else {
			result = additions;
		}
	}

	return Ones_complement(result);
}


bool checker(string sent_message,string rec_message,int block_size){

	string sender_checksum = checkSum(sent_message, block_size);
	string receiver_checksum = checkSum(rec_message + sender_checksum, block_size);

    cout<<"SENDER CHECKSUM AFTER ADDITION :"<<Ones_complement(sender_checksum)<<endl;;
    cout<<"SENDER CHECKSUM AFTER ONE'S COMPLIMENT : "<<sender_checksum<<endl<<endl;
    cout<<"RECEIVER CHECKSUM AFTER ADDITION :"<<Ones_complement(receiver_checksum)<<endl;
    cout<<"RECEIVER CHECKSUM AFTER ONE'S COMPLIMENT : "<<receiver_checksum<<endl;
	
    int zero = count(receiver_checksum.begin(),receiver_checksum.end(),'0');
	if(zero == block_size) {
		return true;
	} else {
		return false;
	}
}

//10000101011000111001010011101101
//10000101011000111001010011101101

int main(){

	cout<<"ENTER THE SENDER DATA : ";
    string s;
    cin>>s;

    cout<<"ENTER THE RECEIVER DATA : ";
    string r;
    cin>>r;

    cout<<"ENTER THE BLOCK SIZE : ";
    int b;
    cin>>b;

    cout<<endl<<endl;
	if (checker(s,r,b)) {
		cout<<"--NO ERROR IS DETECTED--"<<endl;
	} else {
		cout<<"--ERROR IS DETECTED--"<<endl;;
	}

	return 0;
}
