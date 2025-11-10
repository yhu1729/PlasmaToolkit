MIMD
====

Requirement
-----------

* MPICH >= v4.3.2

Example
-------

.. code:

   HYDRA_IFACE=lo0 hydra_nameserver &
   mpirun -n 1 -nameserver localhost ./example_mpi_server > server.log 2>&1 < /dev/null &
   mpirun -n 1 -nameserver localhost ./example_mpi_client > client.log 2>&1 < /dev/null &
   pkill hydra_nameserver

Output
------

server.log

.. code:

   11/04/25 01:39:44.438676 UTC [server] initialize
   11/04/25 01:39:44.487529 UTC [server] open port
   11/04/25 01:39:44.487545 UTC [server] publish service
   11/04/25 01:39:44.488662 UTC [server] wait for connections
   11/04/25 01:39:48.531382 UTC [server] wait for messages
   11/04/25 01:39:48.531448 UTC [server] receive message: 3
   11/04/25 01:39:48.531454 UTC [server] wait for messages
   11/04/25 01:39:48.531478 UTC [server] receive message: 2
   11/04/25 01:39:48.531484 UTC [server] wait for messages
   11/04/25 01:39:48.531689 UTC [server] receive message: 1
   11/04/25 01:39:48.531692 UTC [server] wait for messages
   11/04/25 01:39:48.531726 UTC [server] receive message: 0
   11/04/25 01:39:48.531731 UTC [server] wait for messages
   11/04/25 01:39:48.531759 UTC [server] receive message: 0
   11/04/25 01:39:48.531762 UTC [server] stop
   11/04/25 01:39:48.531798 UTC [server] unpublish service
   11/04/25 01:39:48.532253 UTC [server] finalize

client.log

.. code:

   11/04/25 01:39:48.486736 UTC [client] initialize
   11/04/25 01:39:48.526027 UTC [client] lookup service
   11/04/25 01:39:48.526786 UTC [client] connect
   11/04/25 01:39:48.531382 UTC [client] send message: 3
   11/04/25 01:39:48.531400 UTC [client] send message: 2
   11/04/25 01:39:48.531404 UTC [client] send message: 1
   11/04/25 01:39:48.531410 UTC [client] send message: 0
   11/04/25 01:39:48.531414 UTC [client] send stop
   11/04/25 01:39:48.531417 UTC [client] disconnect
   11/04/25 01:39:48.531488 UTC [client] finalize
