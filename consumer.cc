//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "consumer.h"
#include <string.h>
#include "serviceMsg_m.h"


Define_Module(Consumer);

void Consumer::initialize()
{
    // TODO - Generated method body

   // if (strcmp("consumer1", getName()) == 0)
     //   {
             senderMsg *msg = generateMessage();

            send(msg,"out");
      //}
}

void Consumer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    senderMsg *ttmsg = check_and_cast<senderMsg *>(msg);
    EV << "message name '" << ttmsg->getSource() << "'";
  //  send(ttmsg,"out");
    scheduleAt(simTime()+1,ttmsg);
}

senderMsg *Consumer::generateMessage()
{
    // Produce source and destination addresses.
        int src = getId();  // our module index
        char msgname[20];
        EV << getId();
        sprintf(msgname, "tic id: - %d", src);

        // Create message object and set source and destination field.
        senderMsg *msg = new senderMsg(msgname);
        msg->setSource(src);

        return msg;

}

