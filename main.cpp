#include <iostream>
#include <string>
#include <vector>
#include<string>
#include <chrono>


using namespace std;
const string start("!A");
const string stop("*");


int main()
{
    string::size_type index=0, index1=1;
    string FirstFragment="";
    string LastFragment="";
    string CombinedMessage="";

    string str1="225J4,0*08!AIVDM,1,1,,B,36:RS:001?87bnt=:rq68TnN00nh,0*20!AIVDM,2,1,6,B,56:fS:D0000000000008v0<QD4r0`T4v3400000t0`D147?ps1P00000,0*3D!AIVDM,2,2,6,B,000000000000008,2*29!AIVDM,1,1,,B,15SPL@00000=L5H";
    //string str1="";
    string str2="MD:qqfqu225J4,0*08!AIVDM,1,1,,A,13n3aW0PCkPJS8>Qhc2<urG02D13,0*18!AIVDM,1,1,,B,4h2=aCAuho;QNOUQrvQ6?a1000S:,0*5D";

    while(true){

        cout << "Initial Msg is : " << str1 << endl;
        cout << "Second Portion is : " << str2 << endl << endl;

//if (index !=0){
//            index1=index1-index; }                       //Just checking if the initial index different than 0, substract same from the stop index1 value...

    while ((index < str1.length()) || (index1 < str1.length())){ //both indexes are within the limit...

        index= str1.find(start);
        index1=str1.find(stop);

        cout << "Start char found at : " << index << endl;
        cout << "Stop sign found at : " << index1 << endl;
        cout << "Stop + 3 = Start : " << index1 + 3 << endl << endl;



        if (index1 < index ) {
            cout << "Inside the fisrt condition : " << endl;
            LastFragment=str1.substr(0,index1+3);    //this is the case we do not have the first portion of the message...
            cout << "End of Former Fragment is : " <<LastFragment << endl;
            str1.erase(0,index1+3);
            //cout << "String swapped ?: " << str1 << endl;
            //Wait for next message to arrive...

        }
        else {
            if ((index < index1) && (index1 < str1.length())) {     //This is the case we have both delimitters in the buffered message...
                cout << "The secondation is met ... " << endl;      // this section is contradicting with the others...
                str1.substr(index,index1+3);
                cout << "Queued Message will be : " << str1.substr(index,index1+3) << endl;
                //Will be pushed to Queue...
                str1.erase(index,index1+3);
                cout << "Final State of String : " << str1 << endl; //This will be moved to next ciycle...

           }
            else{

                    if (LastFragment != "") {       // This is the case we have a msg beginning but not the rest...
                        cout << "Fragmentation complation progress... " << endl;
                        FirstFragment=str1.substr(0,str1.length());
                        cout << "Starting portion of Fragment is __: " << FirstFragment << endl;
                        str1.erase(0,str1.length());
                        cout << "Final state of the sentence : " << str1 << endl;
                        CombinedMessage= FirstFragment + LastFragment;
                        cout << "Combined Fragment is : " << CombinedMessage    << endl;
                        //Push that to Queue...
                    }
                    else {
                        cout << "Final state of the sentence : " << str1 << endl;

                        cout << "Mesajın son halinin uzunluğu : " << str1.length() << endl;
                        LastFragment =  str1.substr(index, str1.length());
                        cout << LastFragment<< endl;
                            //str1.erase(index,str1.length());

                    }

            }


    }
cout << "Out of While loop... " << endl;







            //cout << "No shit found... " << endl;
            //exit (0);


}
    if (str2==""){exit (0);}

    if (LastFragment!=""){
      cout << "This first cycle is completed and swithing the sentences... " << endl;
        str1=str2;
        str2="";
        }


    }
}

/*
     while (lastMessageIndex < queuedMessages.length()) {

         std::size_t currentMessageIndex = queuedMessages.find(HEADER_SUBSTRING,lastMessageIndex);

         // check if we are processing the remainder of a previously processed....
         if (lastMessageIndex == 0 && previousFragment.length() != 0 && currentMessageIndex != 0) {
             message = previousFragment + queuedMessages.substr(0,currentMessageIndex-HEADER_SUBSTRING.length());
             previousFragment = "";
         }

         else {
             std::size_t startOfNextMessage = queuedMessages.find(HEADER_SUBSTRING,currentMessageIndex+1);

             // this is the case where there are more messages to process....
             if (startOfNextMessage != std::string::npos) {
                 message = queuedMessages.substr(currentMessageIndex, startOfNextMessage - currentMessageIndex);
                 lastMessageIndex = startOfNextMessage;
             }

             // this is potentially a partial message...
             else {
                 std::string endOfMessage = queuedMessages.substr(queuedMessages.length() - END_OF_MESSAGE_DELIMITER.length() -2, END_OF_MESSAGE_DELIMITER.length());


                 // if this is the last message in the buffer...process it
                 if (endOfMessage.compare(END_OF_MESSAGE_DELIMITER) == 0) {

                     message = queuedMessages.substr(currentMessageIndex, queuedMessages.length() - currentMessageIndex);
                     lastMessageIndex = queuedMessages.length();

                     // this message spans multiple socket reads...
                 } else {

                     previousFragment = queuedMessages.substr(currentMessageIndex, queuedMessages.length() - currentMessageIndex);
                     lastMessageIndex = queuedMessages.length();
                     message = "";
                 }
             }

         }*/
