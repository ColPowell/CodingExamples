    def get_drive_letter(self, MediaType, size, InterfaceType="USB", pattern=None):
    #def get_drive_letter(self,MediaType):
        """
        For HP pendrive of 16 GB capacity
        get_drive_letter("Removable Media", 16, "USB","Reader")

        For emmc of capacity 32 GB
        get_drive_letter("Fixed had disk media", 32,"SCSI","MMC")
        make arguments just one variable: MediaType.
        MediaType would be a reference to the config file with all devices
        If MediaType will have the full type like "thumbdrive_eight_gb_2.0"
        just break it up into variables already used.
        
        """
        #labels = open('C:\Users\cmpowell\Documents\USB automation files\device-config.xml')
        c = wmi.WMI ()
        pattern_match_true=0
        device_capacity=0
        for physical_disk in c.Win32_DiskDrive ():
                for partition in physical_disk.associators ("Win32_DiskDriveToDiskPartition"):
                    for logical_disk in partition.associators ("Win32_LogicalDiskToPartition"):
    #                    print physical_disk.Caption, partition.Caption, logical_disk.Caption, logical_disk.Size, physical_disk.MediaType
    #                    , physical_disk.PNPDeviceID
                        if physical_disk.MediaType == MediaType and physical_disk.InterfaceType == InterfaceType :
                            if  pattern == None:
                                if self.check_storage_capacity(int(physical_disk.Size),size):
                                    logging.debug("Drive=%s Name=%s capacity=%.2fGB \nHardwareid=%s"%(logical_disk.Caption, physical_disk.Caption, (float(physical_disk.Size)/2**30), physical_disk.PNPDeviceID))
                                    return logical_disk.Caption
                            elif search(pattern,physical_disk.Caption):
                                pattern_match_true=1
                                if int(physical_disk.Size)/2**30 > device_capacity:
                                    drive_letter_having_pattern_match=logical_disk.Caption
                                    hardware_id_having_pattern_match=physical_disk.PNPDeviceID
                                    device_capacity_having_pattern_match=float(physical_disk.Size)/2**30
                                    device_name_having_pattern_match=physical_disk.Caption

                                if self.check_storage_capacity(int(physical_disk.Size),size):
                                    logging.debug("Drive=%s Name=%s capacity=%.2fGB \nHardwareid=%s"%(logical_disk.Caption, physical_disk.Caption, (float(physical_disk.Size)/2**30), physical_disk.PNPDeviceID))
                                    return logical_disk.Caption
        else:
            if pattern_match_true==1:
                logging.debug("Drive=%s Name=%s capacity=%.2fGB \nHardwareid=%s"%(drive_letter_having_pattern_match, device_name_having_pattern_match, device_capacity_having_pattern_match, hardware_id_having_pattern_match))
                return drive_letter_having_pattern_match
            if pattern:
                deviceSearched=pattern+' '+str(size)
            else:
                deviceSearched=str(size)
            if self.device_not_found_messagebox(deviceSearched):
                return 0
            else:
                #increased the delay to 20 Sec for the next execution after RETRY is hit,
                #as device take soemtime for being recognised after plugin
                sleep(20)
                new_MediaType= MediaType
                new_size= size
                new_pattern= pattern
                new_InterfaceType=InterfaceType
                drive_letter=self.get_drive_letter(MediaType=new_MediaType,size= new_size, InterfaceType=new_InterfaceType,pattern= new_pattern)
                if drive_letter:
                    return drive_letter
