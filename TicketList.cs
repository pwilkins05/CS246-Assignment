/*******************************
 *
 * Ticket List
 *
 * Starter code by Alex Crippen
 * Last Modified: 02/11/2014 6:10pm
 *
******************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RaffleDraw
{
     public class TicketList
    {
	///BUG///
        private List<Ticet> tickets;

            public delegate void ChangeHandler(TicketList tickets);
            public event ChangeHandler Changed;


            public Ticket this[int i] //indexer
            {
                get
                {
                    return tickets[i];
                }
                set
                {
                    tickets[i] = value;
                    Changed(this);
                }
            }

            public TicketList()
            {
                tickets = new List<Ticket>();
            }

            public void Fill()
            {
                tickets = TicketDB.GetTickets();
            }

            public override string ToString()
            {
		///BUG///
                string str;
                foreach (Ticket c in tickets)
                {
                    str += (c.ToString() + "\n");
                }
                return str;
            }


            public int Count
            {
                get { return tickets.Count; }
            }

            public void Add(Ticket ticket)
            {
                tickets.Add(ticket);
            }

            public void Add(string fName, string lName, string em)
            {
                Ticket p = new Ticket(fName, em);
                tickets.Add(p);
                Changed(this);
            }

            public Ticket GetTicketByIndex(int i)
            {
                return tickets[i];
            }

            public void Remove(Ticket ticket)
            {
                tickets.Remove(ticket);
                Changed(this);
            }

            public void Save()
            {
                TicketDB.SaveTickets(tickets);
            }

            public static TicketList
        operator -(TicketList cl, Ticket c)
            {
                cl.Remove(c);
                return cl;
            }

            public static TicketList
            operator +(TicketList cl, Ticket c)
            {
	///BUG///
                cl.Add(C);
                return cl;
            }

    }
}
