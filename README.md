# EmbeddedLinux_Task6

## Creating virtual SD card

### Step 1

we create a file with size of 1 GB filled with zeros.

![Screenshot from 2024-01-09 13-14-11](/home/alaa/Pictures/Screenshots/Screenshot from 2024-01-09 13-14-11.png)

### Step 2

Configure the partitions for the SD card. using the command:

![Screenshot from 2024-01-09 13-14-32](/home/alaa/Pictures/Screenshots/Screenshot from 2024-01-09 13-14-32.png)

First partition is the boot partition. We configure it as primary partition, size of 200 MB, Partition Format is "FAT 16", and make it Bootable.

The second partition is root partition. we configure it as extended partition, and give it the rest of the size of the SD card, Partition Format is "Linux", and do not make it Bootable.

![Screenshot from 2024-01-09 13-13-23](/home/alaa/Pictures/Screenshots/Screenshot from 2024-01-09 13-13-23.png)

### Step 3

In this step we to attach the sd.img we created to loop driver, to be as a block storage for it to emulate as a real SD card.

![Screenshot from 2024-01-09 13-42-32](/home/alaa/Pictures/Screenshots/Screenshot from 2024-01-09 13-42-32.png)

### Step 4

Last step is to format the partitions as pre-configured in step 2. First partition as FAT 16, and second partition as ext4.

![Screenshot from 2024-01-09 13-42-55](/home/alaa/Pictures/Screenshots/Screenshot from 2024-01-09 13-42-55.png)

## Mount

After creating the virtual SD card we can now mount it as any other block storage in any directory using the command:

![Screenshot from 2024-01-09 13-48-55](/home/alaa/Pictures/Screenshots/Screenshot from 2024-01-09 13-48-55.png)

And to check where the sd.img is mounted we use:

![Screenshot from 2024-01-09 11-56-11](/home/alaa/Pictures/Screenshots/Screenshot from 2024-01-09 11-56-11.png) 