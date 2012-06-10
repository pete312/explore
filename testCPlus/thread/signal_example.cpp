#include <stdio.h>
#include <pthread.h>
#include <signal.h>

void* sig_handler( void* );

/* global variable used to indicate what signal
 * (if any) has been caught
 */
int handled_signal = -1;

/* mutex to be used whenever accessing the above
 * global data */
pthread_mutex_t sig_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void )
{
        sigset_t signal_set;
        pthread_t sig_thread;

        /* block all signals */
        sigfillset( &signal_set );
        pthread_sigmask( SIG_BLOCK, &signal_set,
                NULL );

        /* create the signal handling thread */
        pthread_create( &sig_thread, NULL,
                sig_handler, NULL );

        for (;;) {
            /* whatever you want your program to
             * do... */

                /* grab the mutex before looking
                 * at handled_signal */
                pthread_mutex_lock( &sig_mutex );

                /* look to see if any signals have
                 * been caught */
                switch ( handled_signal )
                {
                case -1:
                  /* no signal has been caught
                   * by the signal handler */
                  break;

                case 0:
                printf("The signal handler caught"
                " a signal I'm not interested in "
                "(%d)\n",
                 handled_signal );
                 handled_signal = -1;
                 break;

                case SIGQUIT:
                printf("The signal handler caught"
                " a SIGQUIT signal!\n" );
                 handled_signal = -1;
                 break;

                case SIGINT:
                printf(
                "The signal handler caught"
                " a SIGINT signal!\n" );
                 handled_signal = -1;
                 break;
                }
                /* remember to release mutex */
                pthread_mutex_unlock(&sig_mutex);
        }
}

void* sig_handler( void* arg )
{
        sigset_t signal_set;
        int sig;

        for(;;) {
                /* wait for any and all signals */
                sigfillset( &signal_set );
                sigwait( &signal_set, &sig );

                /* when we get this far, we've
                 * caught a signal */

                switch( sig )
                {
                /* whatever you need to do on
                 * SIGQUIT */
                case SIGQUIT:
                  pthread_mutex_lock(&sig_mutex);
                  handled_signal = SIGQUIT;
                  pthread_mutex_unlock(&sig_mutex);
                  break;

                /* whatever you need to do on
                 * SIGINT */
                 case SIGINT:
                  pthread_mutex_lock(&sig_mutex);
                  handled_signal = SIGINT;
                  pthread_mutex_unlock(&sig_mutex);
                  break;

                /* whatever you need to do for
                 * other signals */
                default:
                  pthread_mutex_lock(&sig_mutex);
                  handled_signal = 0;
                  pthread_mutex_unlock(&sig_mutex);
                  break;
                }
        }
        return (void*)0;
}
