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
//
// TODO documentation
//
network main
{
    submodules:

        consumer: Consumer {
            @display("p=49,37");
        }
        balancer: Balancer {
            @display("p=196,26;i=block/dispatch,orange,100;is=n");
        }
        dispatcher: Dispatcher {
            @display("p=196,111");
        }
        producer: Producer {
            @display("p=332,26");
        }
        producer1: Producer {
            @display("p=332,111");
        }
        consumer1: Consumer {
            @display("p=49,111");
        }
    connections:
        consumer.out --> balancer.in1;
        consumer1.out --> balancer.in2;
        balancer.out1 --> producer.in;
        balancer.out2 --> producer1.in;
        dispatcher.in[0] <-- producer.out;
        dispatcher.in[1] <-- producer1.out;
        consumer.in <-- dispatcher.out[0];
        consumer1.in <-- dispatcher.out[1];


}

