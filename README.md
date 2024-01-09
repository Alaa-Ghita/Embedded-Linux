# EmbeddedLinux_Task6

## Creating virtual SD card

### Step 1

we create a file with size of 1 GB filled with zeros.

![Screenshot from 2024-01-09 13-14-11](https://github.com/Alaa-Ghita/Embedded-Linux/assets/151027764/83c78d65-0be3-45dd-8d87-250948c75688)

### Step 2

Configure the partitions for the SD card. using the command:

![Screenshot from 2024-01-09 13-14-32](https://github.com/Alaa-Ghita/Embedded-Linux/assets/151027764/518525c6-837c-491c-9ffa-3c10986acec5)

First partition is the boot partition. We configure it as primary partition, size of 200 MB, Partition Format is "FAT 16", and make it Bootable.

The second partition is root partition. we configure it as extended partition, and give it the rest of the size of the SD card, Partition Format is "Linux", and do not make it Bootable.

![Screenshot from 2024-01-09 13-13-23](https://github.com/Alaa-Ghita/Embedded-Linux/assets/151027764/3de7e872-7389-4754-800c-e2c3758f37c2)


### Step 3

In this step we to attach the sd.img we created to loop driver, to be as a block storage for it to emulate as a real SD card.

![Screenshot from 2024-01-09 13-42-32](https://github.com/Alaa-Ghita/Embedded-Linux/assets/151027764/dca88cf0-6a29-4217-8ba1-09fb91a19c48)

### Step 4

Last step is to format the partitions as pre-configured in step 2. First partition as FAT 16, and second partition as ext4.

![Screenshot from 2024-01-09 13-42-55](https://github.com/Alaa-Ghita/Embedded-Linux/assets/151027764/e717f09d-ea36-4812-9086-a32dd077d998)

## Mount

After creating the virtual SD card we can now mount it as any other block storage in any directory using the command:

![Screenshot from 2024-01-09 13-48-55](https://github.com/Alaa-Ghita/Embedded-Linux/assets/151027764/c0f464db-5e8b-4d6e-9b51-fb3a4575b092)

And to check where the sd.img is mounted we use:

![Screenshot from 2024-01-09 11-56-11](https://github.com/Alaa-Ghita/Embedded-Linux/assets/151027764/85fca905-0753-4dca-8521-2f43f551f32e)

