#include <dcmtk/dcmdata/dcdeftag.h>
#include <dcmtk/dcmdata/dcdicdir.h>
#include <dcmtk/dcmdata/dcistrmz.h>

#include <CLI/CLI.hpp>
#include <cstdlib>
#include <string>

void process(DcmDirectoryRecord* record, int level) {
  if (!record) {
    return;
  }

  OFString record_type;
  record->findAndGetOFString(DCM_DirectoryRecordType, record_type);

  OFString file_id;
  record->findAndGetOFString(DCM_ReferencedFileID, file_id);

  if (record_type == "IMAGE") {
    OFString sop_instance_uid;
    OFString instance_number;

    record->findAndGetOFString(DCM_SOPInstanceUID, sop_instance_uid);
    record->findAndGetOFString(DCM_InstanceNumber, instance_number);

    std::cout << std::string(level * 2, ' ') << "IMAGE: Inst. #"
              << instance_number << " | Path: " << file_id
              << " | UID: " << sop_instance_uid << std::endl;
  } else if (record_type == "SERIES") {
    OFString series_desc;
    record->findAndGetOFString(DCM_SeriesDescription, series_desc);
    OFString body_part;
    record->findAndGetOFString(DCM_BodyPartExamined, body_part);

    std::cout << std::string(level * 2, ' ') << "SERIES: " << series_desc
              << " (" << file_id << ")" << std::endl;
    std::cout << std::string(level * 2, ' ') 
                  << "   Body Part Examined: " << body_part << std::endl;
  } else if (record_type == "PATIENT") {
    OFString patient_name;
    record->findAndGetOFString(DCM_PatientName, patient_name);
    std::cout << std::string(level * 2, ' ') << "PATIENT: " << patient_name
              << std::endl;
  }

  DcmDirectoryRecord* childRecord = record->getSub(0);
  while (childRecord != NULL) {
    process(childRecord, level + 1);
    childRecord = record->nextSub(childRecord);
  }
}

int main(int argc, char* argv[]) {
  CLI::App app{"dcmtk example"};
  argv = app.ensure_utf8(argv);

  std::string dicomdir;
  std::string dictionary;
  app.add_option("--dir", dicomdir, "dicomdir");
  app.add_option("--dic", dictionary, "dicom dictionary");
  CLI11_PARSE(app, argc, argv);

  setenv("DCMDICTPATH", dictionary.c_str(), 1);

  DcmDicomDir ddir(dicomdir.c_str());
  auto condition = ddir.error();
  if (condition.bad()) {
    std::cerr << "fail to open " << dicomdir << std::endl;
    return 0;
  }

  DcmDirectoryRecord& root_record = ddir.getRootRecord();
  process(&root_record, 0);
  return 0;
}
