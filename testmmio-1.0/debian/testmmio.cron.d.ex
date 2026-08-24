#
# Regular cron jobs for the testmmio package.
#
0 4	* * *	root	[ -x /usr/bin/testmmio_maintenance ] && /usr/bin/testmmio_maintenance
