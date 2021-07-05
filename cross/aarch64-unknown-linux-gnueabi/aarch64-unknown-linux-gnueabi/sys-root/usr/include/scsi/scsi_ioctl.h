#ifndef _SCSI_IOCTL_H
#define _SCSI_IOCTL_H 

#define SCSI_IOCTL_SEND_COMMAND 1
#define SCSI_IOCTL_TEST_UNIT_READY 2
#define SCSI_IOCTL_BENCHMARK_COMMAND 3
#define SCSI_IOCTL_SYNC 4			/* Request synchronous parameters */
#define SCSI_IOCTL_START_UNIT 5
#define SCSI_IOCTL_STOP_UNIT 6

#ifdef CONFIG_SYNO_DISK_HIBERNATION
/* kernel defined other scsi ioctl in scsi.h. If you want add new scsi ioctl,
 * you must check scsi.h, too */
#define SD_IOCTL_IDLE 4746
#define SD_IOCTL_SUPPORT_SLEEP 4747
#endif /* CONFIG_SYNO_DISK_HIBERNATION */

#ifdef CONFIG_SYNO_SAS_HOST_DISK_LED_CTRL
#define SD_IOCTL_SASHOST_DISK_LED 4755
#endif /* CONFIG_SYNO_SAS_HOST_DISK_LED_CTRL */

/* The door lock/unlock constants are compatible with Sun constants for
   the cdrom */
#define SCSI_IOCTL_DOORLOCK 0x5380		/* lock the eject mechanism */
#define SCSI_IOCTL_DOORUNLOCK 0x5381		/* unlock the mechanism	  */

#define	SCSI_REMOVAL_PREVENT	1
#define	SCSI_REMOVAL_ALLOW	0

#endif /* _SCSI_IOCTL_H */
