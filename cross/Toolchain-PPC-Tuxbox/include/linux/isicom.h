#ifndef _LINUX_ISICOM_H
#define _LINUX_ISICOM_H

/*#define		ISICOM_DEBUG*/
/*#define		ISICOM_DEBUG_DTR_RTS*/


/*
 *	Firmware Loader definitions ...
 */
 
#define		__MultiTech		('M'<<8)
#define		MIOCTL_LOAD_FIRMWARE	(__MultiTech | 0x01)
#define         MIOCTL_READ_FIRMWARE    (__MultiTech | 0x02)
#define         MIOCTL_XFER_CTRL	(__MultiTech | 0x03)
#define         MIOCTL_RESET_CARD	(__MultiTech | 0x04)

#define		DATA_SIZE	16

typedef	struct	{
		unsigned short	exec_segment;
		unsigned short	exec_addr;
}	exec_record;

typedef	struct	{
		int		board;		/* Board to load */
		unsigned short	addr;
		unsigned short	count;
}	bin_header;

typedef	struct	{
		int		board;		/* Board to load */
		unsigned short	addr;
		unsigned short	count;
		unsigned short	segment;
		unsigned char	bin_data[DATA_SIZE];
}	bin_frame;

#endif	/*	ISICOM_H	*/

